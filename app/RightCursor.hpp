#ifndef RIGHTCURSOR_HPP
#define RIGHTCURSOR_HPP

#include "Command.hpp"


class RightCursor: public Command
{
public:

    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif