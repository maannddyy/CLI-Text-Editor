#ifndef DOWNCURSOR_HPP
#define DOWNCURSOR_HPP

#include "Command.hpp"


class DownCursor: public Command
{
public:

    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif