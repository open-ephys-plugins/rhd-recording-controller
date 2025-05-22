/*
    ------------------------------------------------------------------

    This file is part of the Open Ephys GUI
    Copyright (C) 2014 Open Ephys

    ------------------------------------------------------------------

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "RecControllerOutputEditor.h"
#include "RecControllerOutput.h"
#include <stdio.h>

namespace RecControllerOutputNamespace
{

RecControllerOutputEditor::RecControllerOutputEditor (GenericProcessor* parentNode)
    : GenericEditor (parentNode)

{
    desiredWidth = 220;

    board = (RecControllerOutput*) parentNode;

    addTtlLineParameterEditor (Parameter::STREAM_SCOPE, "ttl_out", 15, 25);
    addTtlLineParameterEditor (Parameter::STREAM_SCOPE, "trigger_line", 15, 65);
    addTtlLineParameterEditor (Parameter::STREAM_SCOPE, "gate_line", 120, 65);
    addBoundedValueParameterEditor (Parameter::PROCESSOR_SCOPE, "event_duration", 120, 25);

    for (auto ed : parameterEditors)
    {
        ed->setLayout (ParameterEditor::Layout::nameOnTop);
        ed->setSize (85, 36);
    }

    triggerButton = std::make_unique<UtilityButton> ("Trigger");
    triggerButton->setBounds (70, 105, 80, 20);
    triggerButton->setFont (FontOptions (12.0f));
    triggerButton->addListener (this);
    addAndMakeVisible (triggerButton.get());
}

void RecControllerOutputEditor::buttonClicked (Button* button)
{
    if (button == triggerButton.get())
    {
        RecControllerOutput* processor = (RecControllerOutput*) getProcessor();
        processor->triggerOutput();
    }
}

} // namespace RecControllerOutputNamespace