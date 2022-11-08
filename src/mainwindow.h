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
 * @file mainwindow.h
 * @copyright (c) 2022 Marco Niederberger
 *
 * @brief Main window class file
 *
 */



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QTreeWidget>
#include "dialogabout.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Main Window class
 * 
 * Holds all methods for the main window
 * 
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

   private:
    /**
     * @brief Clear the detail view
     *
     */
    void clearOutput();
    /**
     * @brief Update tree view
     *
     * Load each port into the tree view and save a reference to the
     * QSerialPortInfo object
     *
     */
    void updateTreeView();
    /**
     * @brief Update detail view on selection
     *
     * @param current Ptr to current selected item in treeConnection
     */
    void updateDetailView(QTreeWidgetItem* current);
    Ui::MainWindow* ui; ///< Ptr to ui
    DialogAbout* dAbout; ///< Ptr to instance of DialogAbout
    QList<QSerialPortInfo> listOfPorts; ///< List of all available ports
};
#endif  // MAINWINDOW_H
