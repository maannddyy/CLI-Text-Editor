#ifndef UPCURSOR_HPP
#define UPCURSOR_HPP

#include "Command.hpp"


class UpCursor: public Command
{
public:

    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif