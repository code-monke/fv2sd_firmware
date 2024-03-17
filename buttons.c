

#include "buttons.h"



struct button BUTTON_BEEPER = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};

struct button BUTTON_ESC = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 4,
		.has_L2 = 1,
		.has_L3 = 1,
		.is_L2_extra = 0,
		.is_L3_extra = 1,  //i am not sure
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		41,
		61,
		0,
	}
};

struct button BUTTON_1 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		30,
		58,
		0,
	}
};

struct button BUTTON_2 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		31,
		59,
		0,
	}
};

struct button BUTTON_3 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		32,
		60,
		0,
	}
};

struct button BUTTON_4 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		33,
		61,
		0,
	}
};

struct button BUTTON_5 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		34,
		62,
		0,
	}
};

struct button BUTTON_6 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		35,
		63,
		0,
	}
};

struct button BUTTON_7 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		36,
		64,
		0,
	}
};

struct button BUTTON_8 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		37,
		65,
		0,
	}
};

struct button BUTTON_9 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		38,
		66,
		0,
	}
};

struct button BUTTON_0 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		39,
		67,
		0,
	}
};

struct button BUTTON_MINUS = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		45,
		68,
		0,
	}
};

struct button BUTTON_EQUALS = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		46,
		69,
		0,
	}
};

struct button BUTTON_TILDE = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		53,
		0,
		0,
	}
};

struct button BUTTON_TAB = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		43,
		0,
		0,
	}
};

struct button BUTTON_Q = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 1,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 1,
	},
	.extra_key = 0,
	.scancodes = {
		20,
		76,
		0,
	}
};

struct button BUTTON_SHIFTPLUS1 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 1,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 1,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		76,
		0,
	}
};

struct button BUTTON_W = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		26,
		74,
		0,
	}
};

struct button BUTTON_F = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		9,
		77,
		0,
	}
};

struct button BUTTON_P = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		19,
		0,
		0,
	}
};

struct button BUTTON_G = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		10,
		0,
		0,
	}
};

struct button BUTTON_J = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		13,
		0,
		0,
	}
};

struct button BUTTON_L = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		15,
		42,
		0,
	}
};

struct button BUTTON_U = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		24,
		42,
		0,
	}
};

struct button BUTTON_Y = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		28,
		42,
		0,
	}
};

struct button BUTTON_SEMICOLON = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		51,
		42,
		0,
	}
};

struct button BUTTON_SHIFTPLUS2 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 1,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};

struct button BUTTON_BACKSLASH = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		49,
		0,
		0,
	}
};

struct button BUTTON_ENTER = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 1,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		40,
		0,
		0,
	}
};

struct button BUTTON_ENTER_1 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 1,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		40,
		0,
		0,
	}
};

struct button BUTTON_CLOSINGSQUAREBRACKET = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 1,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 1,
	},
	.extra_key = 0,
	.scancodes = {
		48,
		80,
		0,
	}
};

struct button BUTTON_A = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 1,
		.is_L2_extra = 0,
		.is_L3_extra = 1,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 1,
	},
	.extra_key = 1,
	.scancodes = {
		4,
		80,
		0,
	}
};

struct button BUTTON_R = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 1,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 1,
	},
	.extra_key = 0,
	.scancodes = {
		21,
		81,
		78,
	}
};

struct button BUTTON_S = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 1,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 1,
	},
	.extra_key = 0,
	.scancodes = {
		22,
		82,
		75,
	}
};

struct button BUTTON_T = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 1,
	},
	.extra_key = 0,
	.scancodes = {
		23,
		79,
		0,
	}
};

struct button BUTTON_D = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 1,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 1,
	},
	.extra_key = 0,
	.scancodes = {
		7,
		79,
		0,
	}
};

struct button BUTTON_H = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		11,
		0,
		0,
	}
};

struct button BUTTON_N = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 1,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 1,
		.is_L2Rep = 1,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		17,
		42,
		0,
	}
};

struct button BUTTON_E = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 1,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 1,
		.is_L2Rep = 1,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		8,
		42,
		0,
	}
};

struct button BUTTON_I = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 1,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 1,
		.is_L2Rep = 1,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		12,
		42,
		0,
	}
};

struct button BUTTON_O = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 1,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 1,
		.is_L2Rep = 1,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		18,
		42,
		0,
	}
};

struct button BUTTON_OPENINGSQUAREBRACKET = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		47,
		0,
		0,
	}
};

struct button BUTTON_APOSTROPHE = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		52,
		0,
		0,
	}
};

struct button BUTTON_Z = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		29,
		42,
		0,
	}
};

struct button BUTTON_X = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 1,
		.is_L2_extra = 0,
		.is_L3_extra = 1,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 3,
	.scancodes = {
		27,
		42,
		0,
	}
};

struct button BUTTON_C = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 1,
		.is_L2_extra = 0,
		.is_L3_extra = 1,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 2,
	.scancodes = {
		6,
		42,
		0,
	}
};

struct button BUTTON_V = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 1,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 1,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		25,
		42,
		0,
	}
};

struct button BUTTON_B = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		5,
		0,
		0,
	}
};

struct button BUTTON_K = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		14,
		0,
		0,
	}
};

struct button BUTTON_M = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		16,
		0,
		0,
	}
};

struct button BUTTON_COMMA = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		54,
		0,
		0,
	}
};

struct button BUTTON_PERIOD = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		55,
		0,
		0,
	}
};

struct button BUTTON_FORWARDSLASH = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 1,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 1,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		56,
		0,
		0,
	}
};

struct button BUTTON_ALTTAB = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 4,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		43,
		0,
		0,
	}
};

struct button BUTTON_L2 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};

struct button BUTTON_REP1 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};

struct button BUTTON_SPACE = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 1,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		44,
		0,
		0,
	}
};

struct button BUTTON_SPACE_1 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 1,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		44,
		0,
		0,
	}
};

struct button BUTTON_REP2 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};

struct button BUTTON_LGUI = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 8,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};

struct button BUTTON_L3 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};

struct button BUTTON_LCTRL = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 1,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};

struct button BUTTON_LSHIFT = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 2,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};

struct button BUTTON_LALT = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 4,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 1,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};











struct button BUTTON_DUMMY1 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};

struct button BUTTON_DUMMY2 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};

struct button BUTTON_DUMMY3 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		42,
		0,
		0,
	}
};

struct button BUTTON_DUMMY4 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		42,
		0,
		0,
	}
};

struct button BUTTON_DUMMY5 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		42,
		0,
		0,
	}
};

struct button BUTTON_DUMMY6 = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		42,
		0,
		0,
	}
};

struct button BUTTON_BACKSPACE = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 0,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		42,
		0,
		0,
	}
};

struct button BUTTON_RSHIFT = {
	.current_scancode = 0,
	.current_extra_key = 0,
	.stuff = {
		.pressed = 0,
		.pressed_L2 = 0,
		.mods = 2,
		.L2_mods = 0,
		.has_L2 = 0,
		.has_L3 = 0,
		.is_L2_extra = 0,
		.is_L3_extra = 0,
		.is_shiftPlus = 0,
		.does_kill_shiftPlus = 0,
		.is_affected_by_shiftPlus = 0,
		.is_redundant = 0,
		.is_L2_redundant = 0,
		.is_repeatable = 0,
		.is_L2Rep = 0,
		.is_L2_repeatable = 0,
	},
	.extra_key = 0,
	.scancodes = {
		0,
		0,
		0,
	}
};
