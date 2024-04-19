/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 14;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 14;       /* vert inner gap between windows */
static const unsigned int gappoh    = 14;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 14;       /* vert outer gap between windows and screen edge */

static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 14;       /* horizontal padding of bar */
static const int horizpadbar        = 86;       /* horizontal padding for statusbar */
static const int vertpadbar         = 8;       /* vertical padding for statusbar */

/*  Display modes of the tab bar: never shown, always shown, shown only in  */
/*  monocle mode in the presence of several windows.                        */
/*  Modes after showtab_nmodes are disabled.                                */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
static const int showtab			= showtab_auto;        /* Default tab bar show mode */
static const int toptab				= True;               /* False means bottom tab bar */

static const int showsystray             = 1;     /* 0 means no systray */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/


static const char *fonts[] = {
    "JetbrainsMono Nerd Font: style=Bold: size=12",
    "NotoSansMono Nerd Font : style=Bold: size=12",
};
static const char dmenu_font[]= {
    "JetbrainsMono Nerd Font: style=Bold: size=12",
};

// Colorscheme
#include "themes/everblush.h"

static const char *const autostart[] = {
    "/home/saikat/.local/src/dwm/autostart.sh",  NULL,
    NULL,
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;

const char *spcmd1[] = { "kitty", "--class", "spterm1" };
const char *spcmd2[] = { "kitty", "--class", "spterm2" };
const char *spcmd3[] = { "kitty", "--class", "spterm3", "-e", "htop" };
const char *spcmd4[] = { "kitty", "--class", "spterm4", "--hold", "-e", "ranger" };
const char *spcmd5[] = { "kitty", "--class", "spterm5", "--hold", "-e", "pulsemixer" };

static Sp scratchpads[] = {
	/* name          cmd  */
	{ "spterm1",  spcmd1},
	{ "spterm2",  spcmd2},
	{ "spterm3",  spcmd3},
	{ "spterm4",  spcmd4},
	{ "spterm5",  spcmd5},
};

/* tagging */
/* static const char *tags[] = { " 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 ", " 7 ", " 8 ", " 9 " }; */
static const          char *tags[]     = { "󰇊","󰇋","󰇌","󰇍","󰇎","󰇏" };
static const          int ulineall     = 0;	/* 1 to show underline on all tags, 0 for just the active ones */
static const unsigned int ulinepad     = 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke  = 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset = 0;	/* how far above the bottom of the bar the line should appear */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class,             instance,   title,          tags mask,  switchtotag,  isfloating,  isterminal,  noswallow,  monitor */
	{ NULL,               NULL,       "Event Tester", 0,          0,            0,           0,           1,          -1 },   /* xev */
	{ "Alacritty",        NULL,       NULL,           0,          0,            0,           1,           0,          -1 },
	{ "kitty",            NULL,       NULL,           0,          0,            0,           1,           0,          -1 },
	{ "st-256color",      NULL,       NULL,           0,          0,            0,           1,           0,          -1 },
	{ "St",               NULL,       NULL,           0,          0,            0,           1,           0,          -1 },
	{ "plasma.emojier",   NULL,       NULL,           0,          0,            1,           0,           0,          -1 },
	{ "firefox",          NULL,       NULL,           1 << 2,     0,            0,           0,           0,          -1 },
	{ "zoom",             NULL,       "Settings",     1 << 4,     1,            1,           0,           0,          -1 },
	{ "zoom",             "zoom",     NULL,           1 << 4,     1,            1,           0,           0,          -1 },
	{ "dolphin",          NULL,       NULL,           1 << 4,     1,            0,           0,           0,          -1 },
	{ "qBittorrent",      NULL,       NULL,           1 << 5,     0,            0,           0,           0,          -1 },
  { NULL,               "spterm1",  NULL,           SPTAG(0),   0,            1,           1,           1,          -1 },
  { NULL,               "spterm2",  NULL,           SPTAG(1),   0,            1,           1,           1,          -1 },
	{ NULL,               "spterm3",  NULL,           SPTAG(2),   0,            1,           1,           1,          -1 },
	{ NULL,               "spterm4",  NULL,           SPTAG(3),   0,            1,           1,           1,          -1 },
	{ NULL,               "spterm5",  NULL,           SPTAG(4),   0,            1,           1,           1,          -1 },
};

/* layout(s) */
static const float mfact        = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
#include "shiftview.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ 	"󰇙 󰬛",    tile 					  },  /* first entry is default */
	{ 	"󰇙 󰬍",    NULL 					  },  /* no layout function means floating behavior */
	{ 	"󰇙 󰬉",    bstack 					},
	{   "󰇙 󰬊",    centeredmaster 	},
	{   "󰇙 󰬎",    grid 					  },
	{ 	"󰇙 [M]",  monocle 				},
	{ 	NULL,     NULL 					  }

	/* {" ﰧ",  bstackhoriz 			} , */
	/* {" 恵",  centeredfloatingmaster 	} , */
	/* {" 頻",  centeredmaster 			} , */
	/* {" ",  deck 					} , */
	/* {" 舘",  dwindle 				} , */
	/* {" ﱖ",  gaplessgrid 			} , */
	/* {" 﩯",  grid 					} , */
	/* {" ﳼ",  horizgrid 				} , */
	/* {" ",  nrowgrid 				} , */
	/* {" ",  spiral 					} , */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2]       = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenu_font, "-nb", dmenu_bg, "-nf", dmenu_fg, "-sb", dmenu_sbg, "-sf", dmenu_sfg, "-l", "10", NULL};
static const char *roficmd[]  = { "rofi", "-show", "drun", NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *fmcmd[]    = { "dolphin", NULL };
static const char *webcmd[]   = { "firefox", NULL };
static const char *calender[] = { "gsimplecal", NULL };

#include "movestack.c"

static Key keys[] = {
{ MODKEY,                       XK_Return,        spawn,           { .v = termcmd } },
{ MODKEY,                       XK_q,             killclient,      {0} },
{ MODKEY,                       XK_w,      		tabmode,        {-1} },
{ MODKEY,                       XK_e,             spawn,           { .v = fmcmd } },
{ MODKEY,                       XK_p,             spawn,           { .v = dmenucmd } },
{ MODKEY,                       XK_r,             spawn,           { .v = roficmd } },
{ MODKEY,                       XK_w,             spawn,           { .v = webcmd } },

{ MODKEY|ShiftMask,             XK_Return,        togglescratch,   { .ui = 0 } },           /* spterm1 */
{ Mod1Mask,                     XK_Return,        togglescratch,   { .ui = 1 } },           /* spterm2 */
{ Mod1Mask|ShiftMask,           XK_b,             togglescratch,   { .ui = 2 } },           /* sptop */
{ Mod1Mask|ShiftMask,           XK_f,             togglescratch,   { .ui = 3 } },           /* spfile */
{ Mod1Mask|ShiftMask,           XK_p,             togglescratch,   { .ui = 4 } },           /* sppulse */

{ MODKEY,                       XK_h,             setmfact,        { .f = -0.05} },
{ MODKEY,                       XK_l,             setmfact,        { .f = +0.05} },

{ MODKEY,                       XK_j,             focusstack,      { .i = +1 } },
{ MODKEY,                       XK_k,             focusstack,      { .i = -1 } },

{ MODKEY|ShiftMask,             XK_j,             movestack,       { .i = +1} },
{ MODKEY|ShiftMask,             XK_k,             movestack,       { .i = -1} },

{ MODKEY|ControlMask,           XK_i,             incnmaster,      { .i = +1 } },
{ MODKEY|ControlMask,           XK_d,             incnmaster,      { .i = -1 } },

{ MODKEY|ControlMask,           XK_b,             togglebar,       {0} },
{ MODKEY,                       XK_s,             togglesticky,    {0} },
{ MODKEY,                       XK_space,         togglefloating,  {0} },
{ MODKEY,                       XK_s,             togglesticky,    {0} },

{ MODKEY,                       XK_backslash,     zoom,            {0} },
{ MODKEY|ShiftMask,             XK_backslash,     focusmaster,     {0} },

{ MODKEY,                       XK_a,             tag,             { .ui = ~0 } },
{ MODKEY|ShiftMask,             XK_a,             view,            { .ui = ~0 } },
{ MODKEY,                       XK_Tab,           view,            {0} },

{ MODKEY,                       XK_Page_Up,       cyclelayout,     { .i = -1 } },
{ MODKEY,                       XK_Page_Down,     cyclelayout,     { .i = +1 } },

{ MODKEY,                       XK_bracketleft,   focusmon,        { .i = -1 } },
{ MODKEY,                       XK_bracketright,  focusmon,        { .i = +1 } },
{ MODKEY|ShiftMask,             XK_bracketleft,   tagmon,          { .i = -1 } },
{ MODKEY|ShiftMask,             XK_bracketright,  tagmon,          { .i = +1 } },

{ MODKEY,                       XK_comma,         shiftview,       { .i = -1 } },
{ MODKEY,                       XK_period,        shiftview,       { .i = +1 } },

{ MODKEY|ShiftMask,             XK_r,             quit,            {1} },
{ MODKEY|ShiftMask,             XK_q,             quit,            {0} },

{ MODKEY|ShiftMask,             XK_Return,        togglescratch,   { .ui = 0 } },           /* spterm1 */
{ Mod1Mask,                     XK_Return,        togglescratch,   { .ui = 1 } },           /* spterm2 */
{ Mod1Mask|ShiftMask,           XK_b,             togglescratch,   { .ui = 2 } },           /* spterm3 */
{ Mod1Mask|ShiftMask,           XK_f,             togglescratch,   { .ui = 3 } },           /* spterm4 */
{ Mod1Mask|ShiftMask,           XK_p,             togglescratch,   { .ui = 4 } },           /* spterm5 */

{ MODKEY,                       XK_0,             togglegaps,      {0} },
{ MODKEY|ShiftMask,             XK_0,             defaultgaps,     {0} },
{ MODKEY,                       XK_equal,         incrgaps,        { .i = +1 } },
{ MODKEY,                       XK_minus,         incrgaps,        { .i = -1 } },
{ MODKEY,                       XK_i,             incrigaps,       { .i = +1 } },
{ MODKEY|ShiftMask,             XK_i,             incrigaps,       { .i = -1 } },
{ MODKEY,                       XK_o,             incrogaps,       { .i = +1 } },
{ MODKEY|ShiftMask,             XK_o,             incrogaps,       { .i = -1 } },
{ MODKEY,                       XK_6,             incrihgaps,      { .i = +1 } },
{ MODKEY|ShiftMask,             XK_6,             incrihgaps,      { .i = -1 } },
{ MODKEY,                       XK_7,             incrivgaps,      { .i = +1 } },
{ MODKEY|ShiftMask,             XK_7,             incrivgaps,      { .i = -1 } },
{ MODKEY,                       XK_8,             incrohgaps,      { .i = +1 } },
{ MODKEY|ShiftMask,             XK_8,             incrohgaps,      { .i = -1 } },
{ MODKEY,                       XK_9,             incrovgaps,      { .i = +1 } },
{ MODKEY|ShiftMask,             XK_9,             incrovgaps,      { .i = -1 } },

{ MODKEY,                       XK_t,             setlayout,       { .v = &layouts[0]} },   /* Tile */
{ MODKEY,                       XK_f,             setlayout,       { .v = &layouts[1]} },   /* Floating */
{ MODKEY|ShiftMask,             XK_t,             setlayout,       { .v = &layouts[2]} },   /* Bottomstack */
{ MODKEY,                       XK_c,             setlayout,       { .v = &layouts[3]} },   /* Centeredmaster */
{ MODKEY,                       XK_g,             setlayout,       { .v = &layouts[4]} },   /* Gird */
{ MODKEY,                       XK_m,             setlayout,       { .v = &layouts[5]} },   /* Monocole */

//{ MODKEY|Mod1Mask,  XK_,             setlayout,       { .v = &layouts[]} },   /* Bottomstack Horizontal */
//{ MODKEY|Mod1Mask,  XK_,             setlayout,       { .v = &layouts[]} },   /* Centeredmaster */
//{ MODKEY|Mod1Mask,  XK_,             setlayout,       { .v = &layouts[]} },   /* Centeredmaster Floating */
//{ MODKEY|Mod1Mask,  XK_,             setlayout,       { .v = &layouts[]} },   /* Deck */
//{ MODKEY|Mod1Mask,  XK_,             setlayout,       { .v = &layouts[]} },   /* Dwindle */
//{ MODKEY|Mod1Mask,  XK_,             setlayout,       { .v = &layouts[]} },   /* Gird */
//{ MODKEY|Mod1Mask,  XK_,             setlayout,       { .v = &layouts[]} },   /* Gird Gapless*/
//{ MODKEY|Mod1Mask,  XK_,             setlayout,       { .v = &layouts[]} },   /* Gird Horizontal *1/
//{ MODKEY|Mod1Mask,  XK_,             setlayout,       { .v = &layouts[]} },   /* Gird Row *1/
//{ MODKEY|Mod1Mask,  XK_,             setlayout,       { .v = &layouts[]} },   /* Spiral */

TAGKEYS ( XK_1,                 0 )
TAGKEYS ( XK_2,                 1 )
TAGKEYS ( XK_3,                 2 )
TAGKEYS ( XK_4,                 3 )
TAGKEYS ( XK_5,                 4 )
TAGKEYS ( XK_6,                 5 )
/* TAGKEYS ( XK_7,                6 ) */
/* TAGKEYS ( XK_8,                7 ) */

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkStatusText,        0,              Button3,        spawn,          {.v = calender} },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTabBar,            0,              Button1,        focuswin,       {0} },
};
