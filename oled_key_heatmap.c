#include QMK_KEYBOARD_H
#include "oled_key_heatmap.h"

// Option 1: Using matrix rows and columns
static uint16_t key_presses[MATRIX_ROWS][MATRIX_COLS] = {0};

// Function to update the keypress count
void update_key_heatmap(uint16_t keycode) {
    uint8_t row = keycode / MATRIX_COLS;
    uint8_t col = keycode % MATRIX_COLS;

    if (row < MATRIX_ROWS && col < MATRIX_COLS) {
        key_presses[row][col]++;
    }
}

// Function to display the heatmap on the OLED
void render_key_heatmap(void) {
    char buffer[16];
    oled_write_ln("Key Heatmap:", false);
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            snprintf(buffer, sizeof(buffer), "R%u C%u: %04u", row, col, key_presses[row][col]);
            oled_write_ln(buffer, false);
        }
    }
}

