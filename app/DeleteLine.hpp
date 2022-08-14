#ifndef DELETELINE_HPP
#define DELETELINE_HPP
#include "Command.hpp"
#include <string>

class DeleteLine: public Command
{
public:
    DeleteLine()
    {
        prev = {"", 0};
    }

    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    std::string prev;
};

#endif