#ifndef config_h_INCLUDED
#define config_h_INCLUDED

#define DEFAULT_FONT "Sans 18"
#define DEFAULT_ROUNDING 5
static const int transparency = 128;

struct clr_scheme schemes[] = {
{
  /* colors */
  .bg = {.bgra = {0, 100, 0, transparency},
  .fg = {.bgra = {10, 100, 10, transparency}},
  .high = {.bgra = {33, 100, 33, transparency}},
  .swipe = {.bgra = {100, 33, 100, 64}},
  .text = {.color = UINT32_MAX},
  .font = DEFAULT_FONT,
  .rounding = DEFAULT_ROUNDING,
},
{
  /* colors */
  .bg = {.bgra = {0, 0, 0, transparency}},
  .fg = {.bgra = {10, 10, 10, transparency}},
  .high = {.bgra = {33, 33, 33, transparency}},
  .swipe = {.bgra = {100, 33, 100, 64}},
  .text = {.color = UINT32_MAX},
  .font = DEFAULT_FONT,
  .rounding = DEFAULT_ROUNDING,
}
};

/* layers is an ordered list of layouts, used to cycle through */
static enum layout_id layers[] = {
  Full, // First layout is the default layout on startup
  Special,
  NumLayouts // signals the last item, may not be omitted
};

/* layers is an ordered list of layouts, used to cycle through */
static enum layout_id landscape_layers[] = {
  Full, // First layout is the default layout on startup
  Special,
  NumLayouts // signals the last item, may not be omitted
};

#endif // config_h_INCLUDED
