#include "NewLine.hpp"


void NewLine::execute(EditorModel& model) 
{
    prev = model.newLine();
}

void NewLine::undo(EditorModel& model)
{
    model.undoNewLine(prev);
}