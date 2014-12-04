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

#include <QtGui/QKeyEvent>

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
    
    setupActions();
    setupMenu();
    setupWidgets();
    setupConnections();
}

MainWindow::~MainWindow()
{
}

bool MainWindow::keyPressed(Qt::Key key) const
{
    return m_keyStates[key];
}

void MainWindow::keyPressEvent(QKeyEvent * evt)
{
    QWidget::keyPressEvent(evt);
    
    m_keyStates[evt->key()] = true;
}

void MainWindow::keyReleaseEvent(QKeyEvent * evt)
{
    QWidget::keyReleaseEvent(evt);
    
    m_keyStates[evt->key()] = false;
}

void MainWindow::setupActions()
{
    for (int n = 0; n < 2; ++n)
    {
        m_configurePlayer[n] = new QAction(tr("Player &%1").arg(n + 1), this);
    }
}

void MainWindow::setupMenu()
{
    QMenu * fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(qApp->action(Pong::QuitAction));
    
    QMenu * settingsMenu = menuBar()->addMenu(tr("&Settings"));
    QMenu * controlMenu = settingsMenu->addMenu(tr("&Controls"));
    controlMenu->addAction(m_configurePlayer[0]);
    controlMenu->addAction(m_configurePlayer[1]);
}

void MainWindow::setupWidgets()
{
    QWidget * centralWidget = new QWidget(this);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    setCentralWidget(centralWidget);
    
    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->setObjectName(QStringLiteral("mainLayout"));
    centralWidget->setLayout(mainLayout);
    
    QHBoxLayout * playerLayout = new QHBoxLayout();
    playerLayout->setObjectName(QStringLiteral("playerLayout"));
    mainLayout->addLayout(playerLayout);
    
    for (int n = 0; n < 2; ++n)
    {
        m_playerGroup[n] = new QGroupBox(tr("Player %1").arg(n + 1), centralWidget);
        m_playerGroup[n]->setObjectName(QStringLiteral("m_playerGroup[%1]").arg(n));
        playerLayout->addWidget(m_playerGroup[n]);
        
        QFormLayout * layout = new QFormLayout();
        layout->setObjectName(QStringLiteral("layout %1").arg(n));
        m_playerGroup[n]->setLayout(layout);
        
        m_playerControllerCombo[n] = new QComboBox(m_playerGroup[n]);
        m_playerControllerCombo[n]->setObjectName(QStringLiteral("m_playerControllerCombo[%1]").arg(n));
        layout->addRow(tr("Controller:"), m_playerControllerCombo[n]);
        
        m_playerPoints[n] = new QLabel(QStringLiteral("0"), m_playerGroup[n]);
        m_playerPoints[n]->setObjectName(QStringLiteral("m_playerPoints[%1]").arg(n));
        layout->addRow(tr("Points:"), m_playerPoints[n]);
    }
    
    QGroupBox * gameGroup = new QGroupBox(tr("Game"), centralWidget);
    gameGroup->setObjectName(QStringLiteral("gameGroup"));
    mainLayout->addWidget(gameGroup, 1);
}

void MainWindow::setupConnections()
{
    connect(qApp->action(Pong::QuitAction), SIGNAL(triggered()), this, SLOT(close()));
}
