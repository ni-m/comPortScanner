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
 * @file dialogabout.cpp
 * @copyright (c) 2022 Marco Niederberger
 *
 * @brief Window with all informations about the software
 *
 */



#include "dialogabout.h"
#include "ui_dialogabout.h"
#include "version.h"

DialogAbout::DialogAbout(QWidget* parent) : QDialog(parent), ui(new Ui::DialogAbout) {
    ui->setupUi(this);
    replaceVersionInfo();
}

DialogAbout::~DialogAbout() {
    delete ui;
}

/**
 * @brief Replace template text as created in dialogabout.ui with the actual values on compile time
 */
void DialogAbout::replaceVersionInfo() {
    QString currentText = ui->lblAbout->text();

    static_assert(sizeof(version::gitRev) >= 8);
    QString rev = QString::fromUtf8(version::gitRev, 8);

    currentText.replace("#GitHash", rev)
        .replace("#compDate", version::buildDate)
        .replace("#compTime", version::buildTime)
        .replace("#GitLink", version::repoUrl);
    ui->lblAbout->setText(currentText);
}
