DEFAULT_FOLDER = crkbd/rev1

COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
TAP_DANCE_ENABLE = yes

SRC += custom/jk_achordion.c features/achordion.c custom/jk_tapdance.c custom/jk_capsword.c

CFLAGS += -Ikeyboards/crkbd/keymaps/jrkopp/include -Ikeyboards/crkbd/keymaps/jrkopp/features