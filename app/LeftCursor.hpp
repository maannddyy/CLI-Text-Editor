#ifndef LEFTCURSOR_HPP
#define LEFTCURSOR_HPP

#include "Command.hpp"


class LeftCursor: public Command
{
public:

    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif