#ifndef CURSOREND_HPP
#define CURSOREND_HPP

#include "Command.hpp"

class CursorEnd: public Command
{
public:
    CursorEnd()
        : col{0}
    {
    } 
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    unsigned int col;
};

#endif