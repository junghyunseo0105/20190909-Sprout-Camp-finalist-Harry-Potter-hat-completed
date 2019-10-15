// -*- mode: c++ -*-

// Arduino-Compatible Multi-Threading Library (mthread)

// Copyright (C) 2010-2012 Jonathan Lamothe <jonathan@jlamothe.net>

// This program is free software: you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation, either version 3 of
// the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this program.  If not, see:
// http://www.gnu.org/licenses/

// See license.txt for more details.

// * * *

// This program demonstrates the EventHandler class by creating an
// event which will only evaluate true periodically and then run for a
// while before waiting for the condition to evaluate true again.  The
// program reports what's going on over the serial console for the
// demonstration.

#include <mthread.h>

#define COUNT 5
#define SLEEP_TIME 1

class MyEvent : public EventHandler
{
public:
    MyEvent();
protected:
    bool condition();
private:
    int count;
};

MyEvent::MyEvent()
{
    Serial.println("hello");
    count = 0;
}

bool MyEvent::condition()
{
    //sleep(SLEEP_TIME);
    Serial.println("hello");
    return true;
}

void setup()
{
    Serial.begin(9600);
    main_thread_list->add_thread(new MyEvent);
    delay(1000);
}
