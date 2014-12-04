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

#ifndef PLAYER_HXX
#define PLAYER_HXX

#include "Controller.hxx"

#include <Qt>
#include <QtCore/QObject>

class Player
    : public QObject
    , public Controller
{
    Q_OBJECT
    
public:
    Player(QObject * parent = nullptr);
    virtual ~Player();
    
    Qt::Key upKey() const;
    void setUpKey(Qt::Key key);
    Q_PROPERTY(Qt::Key upKey READ upKey WRITE setUpKey)
    
    Qt::Key downKey() const;
    void setDownKey(Qt::Key key);
    Q_PROPERTY(Qt::Key downKey READ downKey WRITE setDownKey)
    
    virtual void update(Ball const * ball, Bat * bat) const;
    
private:
    Qt::Key m_upKey;
    Qt::Key m_downKey;
};

#endif // PLAYER_HXX
