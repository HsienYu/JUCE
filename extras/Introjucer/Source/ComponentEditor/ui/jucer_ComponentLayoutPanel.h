/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-11 by Raw Material Software Ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the GNU General
   Public License (Version 2), as published by the Free Software Foundation.
   A copy of the license is included in the JUCE distribution, or can be found
   online at www.gnu.org/licenses.

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

  ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.rawmaterialsoftware.com/juce for more information.

  ==============================================================================
*/

#ifndef __JUCER_COMPONENTLAYOUTPANEL_JUCEHEADER__
#define __JUCER_COMPONENTLAYOUTPANEL_JUCEHEADER__

#include "jucer_ComponentLayoutEditor.h"
#include "jucer_EditingPanelBase.h"


//==============================================================================
class ComponentLayoutPanel  : public EditingPanelBase
{
public:
    //==============================================================================
    ComponentLayoutPanel (JucerDocument& doc, ComponentLayout& l)
        : EditingPanelBase (doc,
                            new LayoutPropsPanel (doc, l),
                            new ComponentLayoutEditor (doc, l)),
          layout (l)
    {
    }

    ~ComponentLayoutPanel()
    {
        deleteAllChildren();
    }

    void updatePropertiesList()
    {
        ((LayoutPropsPanel*) propsPanel)->updateList();
    }

    Rectangle<int> getComponentArea() const
    {
        return ((ComponentLayoutEditor*) editor)->getComponentArea();
    }

    Image createComponentSnapshot() const
    {
        return ((ComponentLayoutEditor*) editor)->createComponentLayerSnapshot();
    }

    ComponentLayout& getLayout() const noexcept         { return layout;}

private:
    class LayoutPropsPanel  : public Component,
                              public ChangeListener
    {
    public:
        LayoutPropsPanel (JucerDocument& doc, ComponentLayout& l)
            : document (doc), layout (l)
        {
            layout.getSelectedSet().addChangeListener (this);

            addAndMakeVisible (&propsPanel);
        }

        ~LayoutPropsPanel()
        {
            layout.getSelectedSet().removeChangeListener (this);
            clear();
        }

        void resized()
        {
            propsPanel.setBounds (4, 4, getWidth() - 8, getHeight() - 8);
        }

        void changeListenerCallback (ChangeBroadcaster*)
        {
            updateList();
        }

        void clear()
        {
            propsPanel.clear();
        }

        void updateList()
        {
            clear();

            if (layout.getSelectedSet().getNumSelected() == 1) // xxx need to cope with multiple
            {
                if (Component* comp = layout.getSelectedSet().getSelectedItem (0))
                    if (ComponentTypeHandler* const type = ComponentTypeHandler::getHandlerFor (*comp))
                        type->addPropertiesToPropertyPanel (comp, document, propsPanel);
            }
        }

    private:
        JucerDocument& document;
        ComponentLayout& layout;
        PropertyPanel propsPanel;
    };

    ComponentLayout& layout;
};


#endif   // __JUCER_COMPONENTLAYOUTPANEL_JUCEHEADER__
