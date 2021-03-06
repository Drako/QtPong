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

#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include <QtCore/QMap>

#include <QtWidgets/QMainWindow>

class QGroupBox;
class QComboBox;
class QLabel;
class QAction;

class MainWindow
    : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    virtual ~MainWindow();
    
    bool keyPressed(Qt::Key key) const;
    
protected:
    virtual void keyPressEvent(QKeyEvent * evt);
    virtual void keyReleaseEvent(QKeyEvent * evt);
    
private:
    QGroupBox * m_playerGroup[2];
    QComboBox * m_playerControllerCombo[2];
    QLabel * m_playerPoints[2];
    
    QAction * m_configurePlayer[2];
    
    QMap<int, bool> m_keyStates;
    
    void setupActions();
    void setupMenu();
    void setupWidgets();
    void setupConnections();
};

#endif // MAINWINDOW_HXX
