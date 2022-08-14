#include "DeleteLine.hpp"

void DeleteLine::execute(EditorModel& model)
{
    prev = model.deleteLine();
}

void DeleteLine::undo(EditorModel& model)
{
    model.undoDeleteLine(prev);
}