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

#include "Player.hxx"
#include "Pong.hxx"
#include "MainWindow.hxx"

Player::Player(QObject * parent /* = nullptr */)
    : QObject(parent)
{
}

Player::~Player()
{
}

Qt::Key Player::upKey() const
{
    return m_upKey;
}

void Player::setUpKey(Qt::Key key)
{
    m_upKey = key;
}

Qt::Key Player::downKey() const
{
    return m_downKey;
}

void Player::setDownKey(Qt::Key key)
{
    m_downKey = key;
}

void Player::update(Ball const * ball, Bat * bat) const
{
    Q_UNUSED(ball);
    
    if (qApp->mainWindow()->keyPressed(m_downKey))
        bat->moveDown();
    if (qApp->mainWindow()->keyPressed(m_upKey))
        bat->moveUp();
}
