/*
 ==============================================================================
 
 This file is part of the KIWI library.
 Copyright (c) 2014 Pierre Guillot & Eliott Paris.
 
 Permission is granted to use this software under the terms of either:
 a) the GPL v2 (or any later version)
 b) the Affero GPL v3
 
 Details of these licenses can be found at: www.gnu.org/licenses
 
 KIWI is distributed in the hope that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 
 ------------------------------------------------------------------------------
 
 To release a closed-source product which uses KIWI, contact : guillotpierre6@gmail.com
 
 ==============================================================================
 */

#ifndef __DEF_KIWI_MAINMENU__
#define __DEF_KIWI_MAINMENU__

#include "KiwiJuceInstance.h"

//! The Kiwi Application menubar model

namespace Kiwi
{
    class KiwiMainMenuModel : public MenuBarModel
    {
    private:
        weak_ptr<ApplicationCommandManager> m_cmd_manager;
        
    public:
        //! constructor
        KiwiMainMenuModel(shared_ptr<ApplicationCommandManager> commandManagerToWatch);
        
        //! destructor
        ~KiwiMainMenuModel();
        
        //! This method must return a list of the names of the menus.
        StringArray getMenuBarNames() override;
        
        //! return the popup menu to display for a given top-level menu.
        PopupMenu getMenuForIndex(int topLevelMenuIndex, const String& menuName) override;
        
        //! Called when a menu item has been clicked on.
        void menuItemSelected(int menuItemID, int topLevelMenuIndex) override;
        
    private:
        
        ApplicationCommandManager* getCommandManager() const noexcept
        {
            shared_ptr<ApplicationCommandManager> manager = m_cmd_manager.lock();
            return manager ? manager.get() : nullptr;
        }
        
        //! Called by MainMenuModel to create menus
        void createMenu(PopupMenu& menu, const String& menuName);
        
        //! Called by createMenu to create each menu
        void createOpenRecentPatcherMenu    (PopupMenu& menu);
        void createFileMenu                 (PopupMenu& menu);
        void createEditMenu                 (PopupMenu& menu);
        void createViewMenu                 (PopupMenu& menu);
        void createObjectMenu               (PopupMenu& menu);
        void createArrangeMenu              (PopupMenu& menu);
        void createOptionsMenu              (PopupMenu& menu);
        void createWindowMenu               (PopupMenu& menu);
        void createExtraMenu                (PopupMenu& menu);
        void createHelpMenu                 (PopupMenu& menu);
        
        //! Called by MainMenuModel to handle the main menu command
        void handleMainMenuCommand          (int menuItemID);
    };
    
    typedef shared_ptr<KiwiMainMenuModel>	sjMenuBar;
}

#endif
