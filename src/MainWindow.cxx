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

#include "MainWindow.hxx"
#include "Pong.hxx"

#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QComboBox>

MainWindow::MainWindow()
    : QMainWindow()
{
    setWindowTitle(tr("QtPong"));
    setFixedSize(800, 600);
    
    setupMenu();
    setupWidgets();
    setupConnections();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupMenu()
{
    QMenu * fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(qApp->action(Pong::QuitAction));
    
    QMenu * settingsMenu = menuBar()->addMenu(tr("&Settings"));
}

void MainWindow::setupWidgets()
{
    QWidget * centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    QVBoxLayout * mainLayout = new QVBoxLayout(centralWidget);
    centralWidget->setLayout(mainLayout);
    
    QWidget * playerWidget = new QWidget(centralWidget);
    mainLayout->addWidget(playerWidget);
    
    QHBoxLayout * playerLayout = new QHBoxLayout(playerWidget);
    playerWidget->setLayout(playerLayout);
    
    for (int n = 0; n < 2; ++n)
    {
        m_playerGroup[n] = new QGroupBox(tr("Player %1").arg(n + 1), playerWidget);
        playerLayout->addWidget(m_playerGroup[n]);
    }
}

void MainWindow::setupConnections()
{
    connect(qApp->action(Pong::QuitAction), SIGNAL(triggered()), this, SLOT(close()));
}
