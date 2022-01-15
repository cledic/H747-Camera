/*******************************************************************************/
/*  This file is auto-generated by Azure RTOS GUIX Studio. Do not edit this    */
/*  file by hand. Modifications to this file should only be made by running    */
/*  the Azure RTOS GUIX Studio application and re-generating the application   */
/*  specification file(s). For more information please refer to the Azure RTOS */
/*  GUIX Studio User Guide, or visit our web site at azure.com/rtos            */
/*                                                                             */
/*  GUIX Studio Revision 6.1.9.2                                               */
/*  Date (dd.mm.yyyy): 15. 1.2022   Time (hh:mm): 00:09                        */
/*******************************************************************************/


#define GUIX_STUDIO_GENERATED_FILE
#include <stddef.h>
#include "H747_Camera_resources.h"
#include "H747_Camera_specifications.h"

static GX_WIDGET *gx_studio_nested_widget_create(GX_BYTE *control, GX_CONST GX_STUDIO_WIDGET *definition, GX_WIDGET *parent);
MAIN_WINDOW_CONTROL_BLOCK main_window;
GX_DISPLAY main_display_control_block;
GX_WINDOW_ROOT main_display_root_window;
GX_CANVAS  main_display_canvas_control_block;
extern GX_CONST GX_THEME *main_display_theme_table[];
extern GX_CONST GX_STRING *main_display_language_table[];

GX_STUDIO_DISPLAY_INFO H747_Camera_display_table[1] =
{
    {
    "main_display",
    "main_display_canvas",
    main_display_theme_table,
    main_display_language_table,
    MAIN_DISPLAY_THEME_TABLE_SIZE,
    MAIN_DISPLAY_LANGUAGE_TABLE_SIZE,
    MAIN_DISPLAY_STRING_TABLE_SIZE,
    800,                                     /* x resolution                   */
    480,                                     /* y resolution                   */
    &main_display_control_block,
    &main_display_canvas_control_block,
    &main_display_root_window,
    GX_NULL,                                 /* canvas memory area             */
    1536000,                                 /* canvas memory size in bytes    */
    GX_SCREEN_ROTATION_NONE                  /* rotation angle                 */
    }
};


UINT gx_studio_button_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_BUTTON *button = (GX_BUTTON *) control_block;
    status = gx_button_create(button, info->widget_name, parent, info->style, info->widget_id, &info->size);
    return status;
}

UINT gx_studio_window_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_WINDOW *window = (GX_WINDOW *) control_block;
    GX_WINDOW_PROPERTIES *props = (GX_WINDOW_PROPERTIES *) info->properties;
    status = gx_window_create(window, info->widget_name, parent, info->style, info->widget_id, &info->size);
    if (status == GX_SUCCESS)
    {
        if (props->wallpaper_id)
        {
            gx_window_wallpaper_set(window, props->wallpaper_id, info->style & GX_STYLE_TILE_WALLPAPER);
        }
    }
    return status;
}

UINT gx_studio_numeric_scroll_wheel_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_NUMERIC_SCROLL_WHEEL *wheel = (GX_NUMERIC_SCROLL_WHEEL *) control_block;
    GX_NUMERIC_SCROLL_WHEEL_PROPERTIES *props = (GX_NUMERIC_SCROLL_WHEEL_PROPERTIES *) info->properties;
    status = gx_numeric_scroll_wheel_create(wheel, info->widget_name, parent, props->start_val, props->end_val, 
                                    info->style, info->widget_id, &info->size);
    if (status == GX_SUCCESS)
    {
        if (props->wallpaper_id)
        {
            gx_window_wallpaper_set((GX_WINDOW *) wheel, props->wallpaper_id, info->style & GX_STYLE_TILE_WALLPAPER);
        }
        if(props->selected_background)
        {
            gx_scroll_wheel_selected_background_set((GX_SCROLL_WHEEL *)wheel, props->selected_background);
        }

        if (props->total_rows)
        {
            gx_scroll_wheel_total_rows_set((GX_SCROLL_WHEEL *)wheel, props->total_rows);
        }

        gx_scroll_wheel_selected_set((GX_SCROLL_WHEEL *)wheel, props->selected_row);
        gx_scroll_wheel_gradient_alpha_set((GX_SCROLL_WHEEL *)wheel, props->start_alpha, props->end_alpha);
        gx_scroll_wheel_row_height_set((GX_SCROLL_WHEEL *)wheel, props->row_height);
        gx_text_scroll_wheel_font_set((GX_TEXT_SCROLL_WHEEL *)wheel, props->normal_font, props->selected_font);
#if defined(GUIX_5_4_0_COMPATIBILITY)
        gx_text_scroll_wheel_text_color_set((GX_TEXT_SCROLL_WHEEL *)wheel, props->normal_text_color, props->selected_text_color);
#else
        gx_text_scroll_wheel_text_color_set((GX_TEXT_SCROLL_WHEEL *)wheel, props->normal_text_color, props->selected_text_color, props->disabled_text_color);
#endif
        if(props->callback)
        {
            gx_text_scroll_wheel_callback_set_ext((GX_TEXT_SCROLL_WHEEL *)wheel, (UINT (*)(GX_TEXT_SCROLL_WHEEL*, INT, GX_STRING *))props->callback);
        }
    }
    return status;
}

UINT gx_studio_multi_line_text_view_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_MULTI_LINE_TEXT_VIEW *view = (GX_MULTI_LINE_TEXT_VIEW *) control_block;
    GX_ML_TEXT_VIEW_PROPERTIES *props = (GX_ML_TEXT_VIEW_PROPERTIES *) info->properties;
    status = gx_multi_line_text_view_create(view, info->widget_name, parent, props->string_id, info->style, info->widget_id, &info->size);
    if (status == GX_SUCCESS)
    {
        gx_multi_line_text_view_font_set(view, props->font_id);
#if defined(GUIX_5_4_0_COMPATIBILITY)
        gx_multi_line_text_view_text_color_set(view, props->normal_text_color_id, props->selected_text_color_id);
#else
        gx_multi_line_text_view_text_color_set(view, props->normal_text_color_id, props->selected_text_color_id, props->disabled_text_color_id);
#endif
        gx_multi_line_text_view_whitespace_set(view, props->whitespace);
        gx_multi_line_text_view_line_space_set(view, props->line_space);
    }
    return status;
}
GX_WINDOW_PROPERTIES main_window_properties =
{
    0                                        /* wallpaper pixelmap id          */
};
GX_NUMERIC_SCROLL_WHEEL_PROPERTIES main_window_numeric_scroll_wheel_properties =
{
    0,                                       /* total rows                     */
    0,                                       /* selected row                   */
    50,                                      /* row height                     */
    0,                                       /* start alpha                    */
    0,                                       /* end alpha                      */
    GX_FONT_ID_SYSTEM,                       /* normal font id                 */
    GX_FONT_ID_SYSTEM,                       /* selected font id               */
    GX_COLOR_ID_SHADOW,                      /* normal text color id           */
    GX_COLOR_ID_TEXT,                        /* selected text color id         */
    GX_COLOR_ID_DISABLED_TEXT,               /* disabled text color id         */
    0,                                       /* wallpaper id                   */
    0,                                       /* selected background            */
    GX_NULL,                                 /* format callback                */
    0,                                       /* start val                      */
    9,                                       /* end val                        */
};
GX_ML_TEXT_VIEW_PROPERTIES main_window_text_view_properties =
{
    GX_STRING_ID_STRING_3,                   /* string id                      */
    GX_FONT_ID_TEXT_INPUT,                   /* font id                        */
    GX_COLOR_ID_TEXT_INPUT_TEXT,             /* normal text color              */
    GX_COLOR_ID_TEXT_INPUT_TEXT,             /* selected text color            */
    GX_COLOR_ID_DISABLED_TEXT,               /* disabled text color            */
    0,                                       /* whitespace                     */
    2                                        /* line_space                     */
};

GX_CONST GX_STUDIO_WIDGET main_window_text_view_define =
{
    "text_view",
    GX_TYPE_MULTI_LINE_TEXT_VIEW,            /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_THIN|GX_STYLE_ENABLED|GX_STYLE_TEXT_LEFT,   /* style flags */
    0,                                       /* status flags                   */
    sizeof(GX_MULTI_LINE_TEXT_VIEW),         /* control block size             */
    GX_COLOR_ID_TEXT_INPUT_FILL,             /* normal color id                */
    GX_COLOR_ID_WINDOW_FILL,                 /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_multi_line_text_view_create,     /* create function              */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {-1, 96, 718, 479},                      /* widget size                    */
    GX_NULL,                                 /* no next widget                 */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(MAIN_WINDOW_CONTROL_BLOCK, main_window_text_view), /* control block */
    (void *) &main_window_text_view_properties /* extended properties          */
};

GX_CONST GX_STUDIO_WIDGET main_window_numeric_scroll_wheel_define =
{
    "numeric_scroll_wheel",
    GX_TYPE_NUMERIC_SCROLL_WHEEL,            /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_THIN|GX_STYLE_ENABLED|GX_STYLE_WRAP|GX_STYLE_TEXT_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_NUMERIC_SCROLL_WHEEL),         /* control block size             */
    GX_COLOR_ID_WINDOW_FILL,                 /* normal color id                */
    GX_COLOR_ID_WINDOW_FILL,                 /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_numeric_scroll_wheel_create,     /* create function              */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {740, 213, 780, 452},                    /* widget size                    */
    &main_window_text_view_define,           /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(MAIN_WINDOW_CONTROL_BLOCK, main_window_numeric_scroll_wheel), /* control block */
    (void *) &main_window_numeric_scroll_wheel_properties /* extended properties */
};

GX_CONST GX_STUDIO_WIDGET main_window_button_define =
{
    "button",
    GX_TYPE_BUTTON,                          /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_RAISED|GX_STYLE_ENABLED|GX_STYLE_BUTTON_TOGGLE,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_BUTTON),                       /* control block size             */
    GX_COLOR_ID_BTN_LOWER,                   /* normal color id                */
    GX_COLOR_ID_BTN_UPPER,                   /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_button_create,                 /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {731, 116, 784, 164},                    /* widget size                    */
    &main_window_numeric_scroll_wheel_define, /* next widget definition        */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(MAIN_WINDOW_CONTROL_BLOCK, main_window_button), /* control block  */
    (void *) GX_NULL                         /* no extended properties         */
};

GX_CONST GX_STUDIO_WIDGET main_window_define =
{
    "main_window",
    GX_TYPE_WINDOW,                          /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_ENABLED,   /* style flags                    */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(MAIN_WINDOW_CONTROL_BLOCK),       /* control block size             */
    GX_COLOR_ID_WINDOW_FILL,                 /* normal color id                */
    GX_COLOR_ID_WINDOW_FILL,                 /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_window_create,                 /* create function                */
    GX_NULL,                                 /* drawing function override      */
    (UINT (*)(GX_WIDGET *, GX_EVENT *)) main_screen_event_handler, /* event function override */
    {-1, 0, 798, 479},                       /* widget size                    */
    GX_NULL,                                 /* next widget                    */
    &main_window_button_define,              /* child widget                   */
    0,                                       /* control block                  */
    (void *) &main_window_properties         /* extended properties            */
};
GX_CONST GX_STUDIO_WIDGET_ENTRY H747_Camera_widget_table[] =
{
    { &main_window_define, (GX_WIDGET *) &main_window },
    {GX_NULL, GX_NULL}
};

static GX_WIDGET *gx_studio_nested_widget_create(GX_BYTE *control, GX_CONST GX_STUDIO_WIDGET *definition, GX_WIDGET *parent)
{
    UINT status = GX_SUCCESS;
    GX_WIDGET *widget = GX_NULL;
    GX_VALUE   list_count = 0;
    GX_VALUE   list_total_count = 0;

    if(parent && (parent->gx_widget_type == GX_TYPE_MENU))
    {
        list_total_count = ((GX_MENU *)parent)->gx_menu_list_total_count;
    }

    while(definition && status == GX_SUCCESS)
    {
        if (definition->create_function)
        {
            if (definition->style & GX_STYLE_DYNAMICALLY_ALLOCATED)
            {
                status = gx_widget_allocate(&widget, definition->control_block_size);
                if (status != GX_SUCCESS)
                {
                    return GX_NULL;
                }
            }
            else
            {
                if (control == GX_NULL)
                {
                    return GX_NULL;
                }
                widget = (GX_WIDGET *) (control + definition->control_block_offset);
            }

            status = definition->create_function(definition, widget, parent);

            if(list_count < list_total_count)
            {
                gx_menu_insert((GX_MENU *)parent, widget);
                ((GX_MENU *)parent)->gx_menu_list_total_count--;
                list_count++;
            }

            if (status == GX_SUCCESS)
            {
                if (definition->widget_type != GX_TYPE_TEMPLATE)
                {
#if defined(GUIX_5_4_0_COMPATIBILITY)
                    gx_widget_fill_color_set(widget, definition->normal_fill_color_id, definition->selected_fill_color_id);
#else
                    gx_widget_fill_color_set(widget, definition->normal_fill_color_id, definition->selected_fill_color_id, definition->disabled_fill_color_id);
#endif
                }

                if (!(definition->status & GX_STATUS_ACCEPTS_FOCUS))
                {
                    gx_widget_status_remove(widget, GX_STATUS_ACCEPTS_FOCUS);
                }

                if (definition->draw_function)
                {
                    gx_widget_draw_set(widget, definition->draw_function);
                }
                if (definition->event_function)
                {
                    gx_widget_event_process_set(widget, definition->event_function);
                }

                #if defined(GX_WIDGET_USER_DATA)
                widget->gx_widget_user_data = definition->user_data;
                #endif

                if (definition->child_widget)
                {
                    gx_studio_nested_widget_create(control, definition->child_widget, widget);
                }
            }
            definition = definition->next_widget;
        }
    }
    return widget;
}

GX_WIDGET *gx_studio_widget_create(GX_BYTE *control, GX_CONST GX_STUDIO_WIDGET *definition, GX_WIDGET *parent)
{
    GX_WIDGET *widget;
    widget = gx_studio_nested_widget_create(control, definition, GX_NULL);

    if (parent && widget)
    {
        gx_widget_attach(parent, widget);
    }
    return widget;
}

UINT gx_studio_named_widget_create(char *name, GX_WIDGET *parent, GX_WIDGET **new_widget)
{
    UINT status = GX_FAILURE;
    GX_CONST GX_STUDIO_WIDGET_ENTRY *entry = H747_Camera_widget_table;
    GX_WIDGET *widget = GX_NULL;

    while(entry->widget_information)
    {
        if (!strcmp(name, entry->widget_information->widget_name))
        {
            widget = gx_studio_widget_create((GX_BYTE *) entry->widget, entry->widget_information, parent);
            if (widget)
            {
                status = GX_SUCCESS;
            }
            break;
        }
        entry++;
    }

    if (new_widget)
    {
        *new_widget = widget;
    }
    return status;
}


UINT gx_studio_display_configure(USHORT display, UINT (*driver)(GX_DISPLAY *),
    GX_UBYTE language, USHORT theme, GX_WINDOW_ROOT **return_root)
{
    GX_CONST GX_THEME *theme_ptr;
    GX_RECTANGLE size;

    GX_STUDIO_DISPLAY_INFO *display_info = &H747_Camera_display_table[display];


/* create the requested display                                                */

    gx_display_create(display_info->display,
                      display_info->name,
                      driver,
                      (GX_VALUE) display_info->x_resolution,
                      (GX_VALUE) display_info->y_resolution);


/* install the request theme                                                   */

    if(display_info->theme_table)
    {
        theme_ptr = display_info->theme_table[theme];
        if(theme_ptr)
        {
            gx_display_color_table_set(display_info->display, theme_ptr->theme_color_table, theme_ptr->theme_color_table_size);
            
/* install the color palette if required                                       */
            if (display_info->display->gx_display_driver_palette_set &&
                theme_ptr->theme_palette != NULL)
            {
                display_info->display->gx_display_driver_palette_set(display_info->display, theme_ptr->theme_palette, theme_ptr->theme_palette_size);
            }

            gx_display_font_table_set(display_info->display, theme_ptr->theme_font_table, theme_ptr->theme_font_table_size);
            gx_display_pixelmap_table_set(display_info->display, theme_ptr->theme_pixelmap_table, theme_ptr->theme_pixelmap_table_size);
            gx_system_scroll_appearance_set(theme_ptr->theme_vertical_scroll_style, (GX_SCROLLBAR_APPEARANCE *) &theme_ptr->theme_vertical_scrollbar_appearance);
            gx_system_scroll_appearance_set(theme_ptr->theme_horizontal_scroll_style, (GX_SCROLLBAR_APPEARANCE *) &theme_ptr->theme_horizontal_scrollbar_appearance);
        }
    }

/* Install the language table.                                                 */

    if(display_info->language_table)
    {
        gx_display_language_table_set_ext(display_info->display, display_info->language_table, (GX_UBYTE) display_info->language_table_size, display_info->string_table_size);
        gx_display_active_language_set(display_info->display, language);
    }

/* Set screen rotation angle.                                                  */

    display_info->display->gx_display_rotation_angle = display_info->rotation_angle;

/* create the canvas for this display                                          */

    gx_canvas_create(display_info->canvas,
                     display_info->canvas_name,
                     display_info->display,
                     GX_CANVAS_MANAGED | GX_CANVAS_VISIBLE,
                     display_info->x_resolution,
                     display_info->y_resolution,
                     display_info->canvas_memory,
                     display_info->canvas_memory_size);

/* Create the root window for this canvas                                      */

    gx_utility_rectangle_define(&size,
                                0, 0,
                                (GX_VALUE) (display_info->x_resolution - 1),
                                (GX_VALUE) (display_info->y_resolution - 1));

    gx_window_root_create(display_info->root_window,
                          display_info->name,
                          display_info->canvas, GX_STYLE_NONE, 0, &size);
    if (return_root)
    {
        *return_root = display_info->root_window;
    }
    return GX_SUCCESS;
}
#undef GUIX_STUDIO_GENERATED_FILE
