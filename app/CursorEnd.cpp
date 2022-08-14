#include "CursorEnd.hpp"

void CursorEnd::execute(EditorModel& model) 
{
    col = model.cursorEnd();
}

void CursorEnd::undo(EditorModel& model)
{
    model.undoCursorEnd(col);
}