/*
 *  Copyright (C) 2014, Felix Bytow <felix.bytow@googlemail.com>
 *
 *  This file is part of QtPong.
 *
 *  QtPong is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  QtPong is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with QtPong.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PONG_HXX
#define PONG_HXX

#include <QtCore/QScopedPointer>

#include <QtWidgets/QApplication>

class MainWindow;

class Pong
    : public QApplication
{
    Q_OBJECT

public:
    Pong(int & argc, char ** argv);
    virtual ~Pong();

    MainWindow * mainWindow();

private:
    QScopedPointer<MainWindow> m_mainWindow;
};

#ifdef qApp
#   undef qApp
#endif
#define qApp (static_cast<Pong *>(QCoreApplication::instance()))

#endif // PONG_HXX
