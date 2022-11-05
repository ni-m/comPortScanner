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
 * @file main.cpp
 * @copyright (c) 2022 Marco Niederberger
 *
 * @brief Contains main entry point into comPortScanner
 *
 */

#include <QApplication>
#include "mainwindow.h"

/** @brief Entry point into project comPortScanner */
int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
