#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include "Command.hpp"


class NewLine: public Command
{
public:
    NewLine()
        : prev{""}
    {

    }
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    std::string prev;
};

#endif