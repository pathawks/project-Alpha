#ifndef TIFILEUTILS_TOKENS_H
#define TIFILEUTILS_TOKENS_H

#define TITOKEN_ARROW     "→"
#define TITOKEN_CHI       "𝜒"
#define TITOKEN_CUBERT    "∛"
#define TITOKEN_DEGREE    "°"
#define TITOKEN_DELTA     "𝛥"
#define TITOKEN_E         "⋿"
#define TITOKEN_e         "𝑒"
#define TITOKEN_F         "𝐅"
#define TITOKEN_GTE       "≥"
#define TITOKEN_i         "𝑖"
#define TITOKEN_LIST_L    "ʟ"
#define TITOKEN_LTE       "≤"
#define TITOKEN_N         "𝐍"
#define TITOKEN_n         "𝑛"
#define TITOKEN_NOT_EQUAL "≠"
#define TITOKEN_PI        "𝜋"
#define TITOKEN_PHAT      "p̂"
#define TITOKEN_SIGMA     "𝜎"
#define TITOKEN_SQRT      "√"
#define TITOKEN_SUMMATION "∑" /* N-ARY SUMMATION */
#define TITOKEN_SUB_N_ONE "₋₁"
#define TITOKEN_SUB_ZERO  "₀"
#define TITOKEN_SUB_ONE   "₁"
#define TITOKEN_SUB_TWO   "₂"
#define TITOKEN_SUB_THREE "₃"
#define TITOKEN_SUB_FOUR  "₄"
#define TITOKEN_SUB_FIVE  "₅"
#define TITOKEN_SUB_SIX   "₆"
#define TITOKEN_SUB_SEVEN "₇"
#define TITOKEN_SUB_EIGHT "₈"
#define TITOKEN_SUB_NINE  "₉"
#define TITOKEN_SUB_TEN   "₁₀"
#define TITOKEN_SUB_r     "ᵣ"
#define TITOKEN_SUP_N_ONE "⁻¹"
#define TITOKEN_SUP_ZERO  "⁰"
#define TITOKEN_SUP_ONE   "¹"
#define TITOKEN_SUP_TWO   "²"
#define TITOKEN_SUP_THREE "³"
#define TITOKEN_SUP_FOUR  "⁴"
#define TITOKEN_SUP_FIVE  "⁵"
#define TITOKEN_SUP_SIX   "⁶"
#define TITOKEN_SUP_SEVEN "⁷"
#define TITOKEN_SUP_EIGHT "⁸"
#define TITOKEN_SUP_NINE  "⁹"
#define TITOKEN_SUP_TEN   "¹⁰"
#define TITOKEN_THETA     "𝛳"
#define TITOKEN_TRIANGLE  "►"
#define TITOKEN_XRT       "ˣ√"
#define TITOKEN_X_MEAN    "x̅"
#define TITOKEN_Y_MEAN    "y̅"

const char* const TI_TOKEN_LISTS[10 + 1] = {
    (char *)10,
    TITOKEN_LIST_L TITOKEN_SUB_ONE,
    TITOKEN_LIST_L TITOKEN_SUB_TWO,
    TITOKEN_LIST_L TITOKEN_SUB_THREE,
    TITOKEN_LIST_L TITOKEN_SUB_FOUR,
    TITOKEN_LIST_L TITOKEN_SUB_FIVE,
    TITOKEN_LIST_L TITOKEN_SUB_SIX,
    TITOKEN_LIST_L TITOKEN_SUB_SEVEN,
    TITOKEN_LIST_L TITOKEN_SUB_EIGHT,
    TITOKEN_LIST_L TITOKEN_SUB_NINE,
    TITOKEN_LIST_L TITOKEN_SUB_ZERO,
};

const char* const TI_TOKEN_Y[10 + 1] = {
    (char *)10,
    "Y" TITOKEN_SUB_ONE,
    "Y" TITOKEN_SUB_TWO,
    "Y" TITOKEN_SUB_THREE,
    "Y" TITOKEN_SUB_FOUR,
    "Y" TITOKEN_SUB_FIVE,
    "Y" TITOKEN_SUB_SIX,
    "Y" TITOKEN_SUB_SEVEN,
    "Y" TITOKEN_SUB_EIGHT,
    "Y" TITOKEN_SUB_NINE,
    "Y" TITOKEN_SUB_ZERO,
};

const char* const TI_TOKEN_STR[10 + 1] = {
    (char *) 10,
    "Str1",
    "Str2",
    "Str3",
    "Str4",
    "Str5",
    "Str6",
    "Str7",
    "Str8",
    "Str9",
    "Str0",
};

const char* const TI_TOKEN_PIC[10 + 1] = {
    (char *) 10,
    "Pic1",
    "Pic2",
    "Pic3",
    "Pic4",
    "Pic5",
    "Pic6",
    "Pic7",
    "Pic8",
    "Pic9",
    "Pic0",
};

const char* const TI_TOKEN_GDB[10 + 1] = {
    (char *) 10,
    "GDB1",
    "GDB2",
    "GDB3",
    "GDB4",
    "GDB5",
    "GDB6",
    "GDB7",
    "GDB8",
    "GDB9",
    "GDB0",
};

const char* const TI_TOKEN_MATRIX[10 + 1] = {
    (char *) 10,
    "[A]",
    "[B]",
    "[C]",
    "[D]",
    "[E]",
    "[F]",
    "[G]",
    "[H]",
    "[I]",
    "[J]",
};

#endif
