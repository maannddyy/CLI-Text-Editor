// InteractionProcessor.cpp
//
// ICS 45C Spring 2022
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            for (auto i = stack.begin(); i < stack.end(); i++)
            {
                delete *i;
            }

            for (auto i = redoStack.begin(); i < redoStack.end(); i++)
            {
                delete *i;
            }
            
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (stack.size() > 0)
            {
                Command* c = stack.back();
                c->undo(model);
                redoStack.push_back(c);
                stack.pop_back();
                model.clearErrorMessage();
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if (redoStack.size() > 0)
            {
                Command* c = redoStack.back();
                c->execute(model);
                stack.push_back(c);
                redoStack.pop_back();
                model.clearErrorMessage();
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                stack.push_back(command);
                redoStack.clear();
                model.clearErrorMessage();
                
                
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            //delete command;
        }
      
    }
}

