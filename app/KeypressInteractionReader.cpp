// KeypressInteractionReader.cpp
//
// ICS 45C Spring 2022
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "RightCursor.hpp"
#include "LeftCursor.hpp"
#include "InsertChar.hpp"
#include "BackSpace.hpp"
#include "UpCursor.hpp"
#include "DownCursor.hpp"
#include "NewLine.hpp"
#include "CursorHome.hpp"
#include "CursorEnd.hpp"
#include "DeleteLine.hpp"


// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
                case 'X':
                {
                    return Interaction::quit();
                }
                case 'O':
                {
                    RightCursor* moveRight = new RightCursor;
                    return Interaction::command(moveRight);
                }

                case 'U':
                {
                    LeftCursor* moveLeft = new LeftCursor;
                    return Interaction::command(moveLeft);
                }

                case 'Z':
                {
                    return Interaction::undo();
                }

                case 'A':
                {
                    return Interaction::redo();
                }

                case 'H':
                {
                    BackSpace* back = new BackSpace;
                    return Interaction::command(back);
                }

                case 'I':
                {
                    UpCursor* up = new UpCursor;
                    return Interaction::command(up);
                }

                case 'K':
                {
                    DownCursor* down = new DownCursor;
                    return Interaction::command(down);
                }

                case 'J':
                {
                    NewLine* newline = new NewLine;
                    return Interaction::command(newline);
                }

                case 'M':
                {
                    NewLine* newline = new NewLine;
                    return Interaction::command(newline);
                }

                case 'Y':
                {
                    CursorHome* home = new CursorHome;
                    return Interaction::command(home);
                }

                case 'P':
                {
                    CursorEnd* end = new CursorEnd;
                    return Interaction::command(end);
                }

                case 'D':
                {
                    DeleteLine* deleteline = new DeleteLine;
                    return Interaction::command(deleteline);
                }
            }
        }
        else
        {
            InsertChar* insertC = new InsertChar{keypress.code()};
            return Interaction::command(insertC);
        }
    }
}

