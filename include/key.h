/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:54:16 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/04 17:55:10 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

typedef enum e_key
{
	KEY_W = 0,
	KEY_A,
	KEY_S,
	KEY_D,
	KEY_M,
	KEY_SHIFT,
	KEY_TAB,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_SPACE,
	KEY_COUNT
}			t_key;

/*
** Keyboard alphabet
*/

# define K_A 97
# define K_B 98
# define K_C 99
# define K_D 100
# define K_E 101
# define K_F 102
# define K_G 103
# define K_H 104
# define K_I 105
# define K_J 106
# define K_K 107
# define K_L 108
# define K_M 109
# define K_N 110
# define K_O 111
# define K_P 112
# define K_Q 113
# define K_R 114
# define K_S 115
# define K_T 116
# define K_U 117
# define K_V 118
# define K_W 119
# define K_X 120
# define K_Y 121
# define K_Z 122

/*
** Keyboard arrows
*/

# define K_LEFT 65361
# define K_UP 65362
# define K_RIGHT 65363
# define K_DOWN 65364

/*
** Keyboard upper row symbols & punctuation/numbers
*/

# define K_TILDE 96
# define K_EXCL 49
# define K_AT 40
# define K_SHARP 51
# define K_DOLLAR 52
# define K_PCENT 53
# define K_CARET 54
# define K_ET 55
# define K_STAR 56
# define K_O_PARENTH 57
# define K_C_PARENTH 48
# define K_DASH 45
# define K_PLUS 61

/*
** Keyboard other punctutation
*/

# define K_SPACE 32
# define K_O_BRACK 91
# define K_C_BRACK 93
# define K_PIPE 92
# define K_SCOLON 59
# define K_QUOTE 39
# define K_COMMA 44
# define K_DOT 46
# define K_SLASH 47

/*
** Keyboard misc.
*/

# define K_ESC 65307
# define K_TAB 65289
# define K_CAPS 65509
# define K_SHIFT_L 65505
# define K_SHIFT_R 65506
# define K_CTRL_L 65507
# define K_CTRL_R 65508
# define K_ALT_L 65513
# define K_ALT_R 65212
# define K_CMD_R 65516
# define K_DEL 65288
# define K_RETURN 65293

/*
** Keyboard function keys
*/

# define K_HOME 65360
# define K_PG_UP 65365
# define K_PG_DN 65366

/*
** Keyboard numeric pad
*/

# define K_NP_CLEAR 65407
# define K_NP_EQUAL 65469
# define K_NP_DOT 65439
# define K_NP_ENTER 65421
# define K_NP_DIV 65455
# define K_NP_MUL 65450
# define K_NP_MIN 65453
# define K_NP_PLU 65451
# define K_NP_0 65438
# define K_NP_1 65436
# define K_NP_2 65433
# define K_NP_3 65435
# define K_NP_4 65430
# define K_NP_5 65437
# define K_NP_6 65432
# define K_NP_7 65429
# define K_NP_8 65431
# define K_NP_9 65434

/*
** Mouse
*/

# define M_CLK_L 1
# define M_CLK_M 2
# define M_CLK_R 3
# define M_SCR_U 4
# define M_SCR_D 5

#endif
