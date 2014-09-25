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

#include "Pong.hxx"
#include "MainWindow.hxx"

#include <QtWidgets/QAction>
#include <QtWidgets/QActionGroup>

Pong::Pong(int & argc, char** argv)
    : QApplication(argc, argv)
{
    setupActions();
    
    m_mainWindow.reset(new MainWindow());
    m_mainWindow->show();
    
    setupConnections();
}

Pong::~Pong()
{
}

MainWindow * Pong::mainWindow()
{
    return m_mainWindow.data();
}

QAction * Pong::action(GlobalAction which)
{
    return m_actions[which];
}

QActionGroup * Pong::actionGroup(GlobalActionGroup which)
{
    return m_actionGroups[which];
}

void Pong::setupActions()
{
    m_actions[QuitAction] = new QAction(tr("Quit"), this);
}

void Pong::setupConnections()
{
}
