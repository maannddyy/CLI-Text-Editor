#include "BackSpace.hpp"

void BackSpace::execute(EditorModel& model)
{
    character = model.backspace();
}

void BackSpace::undo(EditorModel& model)
{
    model.insertCharacter(character);
}