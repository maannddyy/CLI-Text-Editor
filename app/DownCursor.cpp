#include "DownCursor.hpp"


void DownCursor::execute(EditorModel& model) 
{
    model.moveDown();
}

void DownCursor::undo(EditorModel& model)
{
    model.moveUp();
}