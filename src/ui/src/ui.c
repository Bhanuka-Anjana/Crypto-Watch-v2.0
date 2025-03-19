// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.1
// LVGL version: 9.1.0
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////

// SCREEN: ui_HomeScn
void ui_HomeScn_screen_init(void);
void ui_event_HomeScn(lv_event_t * e);
lv_obj_t * ui_HomeScn;
lv_obj_t * ui_starImg;
lv_obj_t * ui_timeLbl;
lv_obj_t * ui_ampmLbl;
lv_obj_t * ui_dateLbl;
lv_obj_t * ui_Panel5;
lv_obj_t * ui_cryptoRateLbl;
lv_obj_t * ui_arrowImg;
lv_obj_t * ui_cryptoPercentageLbl;
lv_obj_t * ui_cryptoNameLbl;
lv_obj_t * ui_stepCountArc;
lv_obj_t * ui_stepCountLbl;
lv_obj_t * ui_stepsLbl;
lv_obj_t * ui_tempuratureArc;
lv_obj_t * ui_tempLbl;
lv_obj_t * ui_batteryArc;
lv_obj_t * ui_Bar1;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Panel1;
// CUSTOM VARIABLES

// SCREEN: ui_MenuScn
void ui_MenuScn_screen_init(void);
lv_obj_t * ui_MenuScn;
lv_obj_t * ui_Image3;
void ui_event_brightnessSlider(lv_event_t * e);
lv_obj_t * ui_brightnessSlider;
lv_obj_t * ui_Label1;
void ui_event_addNewWiFibtn(lv_event_t * e);
lv_obj_t * ui_addNewWiFibtn;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Roller1;
void ui_event_backBtn(lv_event_t * e);
lv_obj_t * ui_backBtn;
lv_obj_t * ui_Label3;
// CUSTOM VARIABLES

// SCREEN: ui_WifiScn
void ui_WifiScn_screen_init(void);
lv_obj_t * ui_WifiScn;
lv_obj_t * ui_wifiTimerArc;
lv_obj_t * ui_backBtn2;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Label4;
bool setOndemardWifi = false;
lv_timer_t * arcTimer;
// CUSTOM VARIABLES

// EVENTS
lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_HomeScn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_active()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_active());
        _ui_screen_change(&ui_MenuScn, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_MenuScn_screen_init);
    }
}

void ui_event_brightnessSlider(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_VALUE_CHANGED) {
        brightnessChangecallback(e);
    }
}

void ui_event_addNewWiFibtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        addNewWiFicallback(e);
        _ui_screen_change(&ui_WifiScn, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 100, &ui_WifiScn_screen_init);
    }
}

void ui_event_backBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        backToHomeCB(e);
    }
}

void ui_event_backBtn2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        cancelWiFiCB(e);
        _ui_screen_change(&ui_MenuScn, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 100, &ui_MenuScn_screen_init);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_display_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_HomeScn_screen_init();
    ui_MenuScn_screen_init();
    ui_WifiScn_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_HomeScn);
}
