#include "menu.h"
#include "transformer_model/transformer_model.h"
#include "transformer_model/attention.h"

inline void no_menu() {}

// Automatically incrementing compile time constant character.
// Used for avoiding selection character collisions in the menu.
#define STARTING_SEL_CHAR 0x31  // '1'
#define AUTO_INC_CHAR __COUNTER__ + STARTING_SEL_CHAR

static struct Menu MENU = {
    "Transformer Model",
    "(sub)layer",
    {
        MENU_ITEM(AUTO_INC_CHAR, "Attention", attention),
        MENU_ITEM(AUTO_INC_CHAR, "Add & Norm", no_menu),
        MENU_ITEM(AUTO_INC_CHAR, "Feed Forward", no_menu),
        MENU_ITEM(AUTO_INC_CHAR, "Encoder", no_menu),
        MENU_ITEM(AUTO_INC_CHAR, "Decoder", no_menu),
        MENU_END,
    },
};

#undef AUTO_INC_CHAR
#undef STARTING_SEL_CHAR

// For integration into menu system
void transformer_menu() { menu_run(&MENU); }
