/******************************************************************************
 * Copyright (C) 2022 by Marco Niederberger                                   *
 *                                                                            *
 * This file is part of comPortScanner                                        *
 *                                                                            *
 * comPortScanner is free software: you can redistribute it and/or modify     *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * comPortScanner is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the               *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with comPortScanner.  If not, see <http://www.gnu.org/licenses/>.    *
 ******************************************************************************/
/**
 * @file mainwindow.cpp
 * @copyright (c) 2022 Marco Niederberger
 *
 * @brief Main window class file
 *
 */

#include "mainwindow.h"
#include <QVariant>
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    dAbout = new DialogAbout;

    clearOutput();     ///< Init empty detail view
    updateTreeView();  ///< Init tree view with com ports

    // menu actions
    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionAbout, &QAction::triggered, dAbout, &DialogAbout::show);

    connect(ui->actionSync, &QAction::triggered, this, &MainWindow::updateTreeView);

    connect(ui->treeConnections, &QTreeWidget::currentItemChanged, this,
            &MainWindow::updateDetailView);

    // disable wait for close, automatic close after main window close
    dAbout->setAttribute(Qt::WA_QuitOnClose, false);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::clearOutput() {
    QLabel* lbl[] = {ui->outSerialNumber, ui->outDesc, ui->outManufacturer, ui->outSystemLocation,
                     ui->outVendorId};

    for (int i = 0; i < sizeof(lbl) / sizeof(lbl[0]); ++i) {
        lbl[i]->setText("N/A");
    }
    ui->groupSingleConn->setTitle("N/A");
}

/**
 * @brief Update tree view acc to the available serial ports
 *
 */
void MainWindow::updateTreeView() {
    ui->treeConnections->clear();
    listOfPorts.clear();
    listOfPorts = QSerialPortInfo::availablePorts();

    for (int i = 0; i < listOfPorts.size(); ++i) {
        QTreeWidgetItem* treeItem = new QTreeWidgetItem(ui->treeConnections);
        treeItem->setText(0, listOfPorts[i].portName());
        treeItem->setText(1, listOfPorts[i].serialNumber());
        treeItem->setText(2, listOfPorts[i].description());
        treeItem->setData(0, Qt::UserRole, QVariant(i));  ///< store index of given connection
    }
    ui->treeConnections->sortItems(0, Qt::AscendingOrder);
}

void MainWindow::updateDetailView(QTreeWidgetItem* current) {
    if (current != nullptr) {
        /// retrieve port info at given index
        QSerialPortInfo port = listOfPorts.value(current->data(0, Qt::UserRole).toInt());

        /// set info in detail view @todo (ni-m) Add N/A if entry is empty
        ui->groupSingleConn->setTitle(port.portName());
        ui->outDesc->setText(port.description());
        ui->outSerialNumber->setText(port.serialNumber());
        ui->outSystemLocation->setText(port.systemLocation());
        ui->outManufacturer->setText(port.manufacturer());
        if (port.hasVendorIdentifier() != 0) {
            ui->outVendorId->setText("0x" +
                                     QString("%1").arg(port.vendorIdentifier(), 4, 16).toUpper());
        }
        ///< @todo (ni-m) Add padding 0
    }
}
