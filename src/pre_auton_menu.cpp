#include "main.h"

/*Initialize global variables*/
const char *autonMode;
const char *driverMode;
/*Variables*/
uint8_t progress_bar_percentage;
bool autonomous_is_done;
bool driver_is_done;

/**
  * Callback for a button press in a button matrix. This callback is intended
	* for the buttons on the left page, which is the autonomous selection side.
	*
	* @param btnm the button matrix(of type lv_obj_t)
	* @param txt the text inside the button
	* @return returns OK because the button matrix is not deleted
  */
static lv_res_t btnm_action_auton(lv_obj_t * btnm, const char *txt){
	printf("Autonomous %s selected\n", txt);

	autonMode = txt;
	autonomous_is_done = !autonomous_is_done;
	progress_bar_percentage += 50;
	return LV_RES_OK;
}

/**
  * Callback for a button press in a button matrix. This callback is intended
	* for the buttons on the right page, which is the driver selection side.
	*
	* @param btnm the button matrix(of type lv_obj_t)
	* @param txt the text inside the button
	* @return returns OK because the button matrix is not deleted
  */
static lv_res_t btnm_action_driver(lv_obj_t * btnm, const char *txt){
	printf("Driver %s selected\n", txt);

	driverMode = txt;
	driver_is_done = !driver_is_done;
	progress_bar_percentage += 50;
	return LV_RES_OK;
}

void menu_task(void* param){
	/*Initialize any variables before drawing up the menu*/
	progress_bar_percentage = 0;
	autonomous_is_done = false;
	driver_is_done = false;

  /*Create a parent screen*/
	lv_obj_t * scr = lv_obj_create(lv_scr_act(), NULL);
	lv_obj_set_size(scr, 480, 300);
	/*Create a screen style*/
	static lv_style_t style_scr;
	lv_style_copy(&style_scr, &lv_style_plain_color);
	style_scr.body.main_color = LV_COLOR_BLACK;
	style_scr.body.grad_color = LV_COLOR_BLACK;
	/*Set screen style*/
	lv_obj_set_style(scr, &style_scr);

	/*Create a bar and a bar indicator style*/
	static lv_style_t style_bar;
	static lv_style_t style_indic;

	lv_style_copy(&style_bar, &lv_style_pretty);
	style_bar.body.main_color = LV_COLOR_BLACK;
	style_bar.body.grad_color = LV_COLOR_GRAY;
	style_bar.body.radius = 0;
	style_bar.body.border.color = LV_COLOR_GRAY;

	lv_style_copy(&style_indic, &lv_style_pretty);
	style_indic.body.grad_color =  LV_COLOR_GREEN;
	style_indic.body.main_color=  LV_COLOR_LIME;
	style_indic.body.radius = 0;
	style_indic.body.shadow.width = 10;
	style_indic.body.shadow.color = LV_COLOR_LIME;
	style_indic.body.padding.hor = 0;
	style_indic.body.padding.ver = 0;

	/*Create a progress bar with proper settings*/
	lv_obj_t * progress_bar = lv_bar_create(scr, NULL);
	lv_obj_set_size(progress_bar, 480, 20);
	lv_obj_align(progress_bar, scr, LV_ALIGN_IN_TOP_LEFT, 0, 0);
	lv_bar_set_value(progress_bar, progress_bar_percentage);
	/*Set style of bar*/
	lv_bar_set_style(progress_bar, LV_BAR_STYLE_BG, &style_bar);
	lv_bar_set_style(progress_bar, LV_BAR_STYLE_INDIC, &style_indic);

	/*Create two individual pages. One side for autonomous, one for driver*/
	lv_obj_t * left_page = lv_page_create(scr, NULL);
	lv_obj_t * right_page =  lv_page_create(scr, NULL);

	/*Create styles for left page*/
	static lv_style_t left_page_style;
	lv_style_copy(&left_page_style, &lv_style_plain_color);
	left_page_style.body.main_color = LV_COLOR_BLACK;
	left_page_style.body.grad_color = LV_COLOR_BLUE;

	/*Set-up left page*/
	lv_obj_set_size(left_page, 240, 220);
	lv_obj_align(left_page, progress_bar, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
	lv_obj_set_style(left_page, &left_page_style);
	lv_page_set_sb_mode(left_page, LV_SB_MODE_AUTO);
	lv_page_set_scrl_fit(left_page, true, true);
	lv_page_set_scrl_height(left_page, 220);

	/*Create style for a line */
	static lv_style_t line_splitter_style;
	lv_style_copy(&line_splitter_style, &lv_style_plain_color);
	line_splitter_style.line.width = 10;
	line_splitter_style.line.color = LV_COLOR_BLACK;

	/*Create two points for the vertical line splitter*/
	static lv_point_t line_splitter_points[] = { {240, 20}, {240, 300}};

	/*Create a line to split the two pages*/
	lv_obj_t * line_splitter = lv_line_create(scr, NULL);
	lv_line_set_points(line_splitter, line_splitter_points, 2);
	lv_obj_set_style(line_splitter, &line_splitter_style);

	/*Create a button descriptor string array*/
	static const char * btnm1_map[] = {"R_S Park", "R_S NoPark", "\n",
															"R_C Park", "R_C NoPark", "\n",
															"B_S Park", "B_S NoPark", "\n",
															"B_C Park", "B_C NoPark", ""};

	/*Create a style for matrix background*/
	static lv_style_t btnm1_style_background;
	lv_style_copy(&btnm1_style_background, &lv_style_plain);
	btnm1_style_background.body.main_color = LV_COLOR_SILVER;
	btnm1_style_background.body.grad_color = LV_COLOR_SILVER;
	btnm1_style_background.body.padding.hor = 0;
	btnm1_style_background.body.padding.ver = 0;
	btnm1_style_background.body.padding.inner = 0;

	/*Create 3 button styles*/
	static lv_style_t btnm1_style_rel;
	static lv_style_t btnm1_style_pr;
	static lv_style_t btnm1_style_ina;

	/*Set button release style*/
	lv_style_copy(&btnm1_style_rel, &lv_style_btn_rel);
	btnm1_style_rel.body.main_color = LV_COLOR_MAKE(0x30, 0x30, 0x30);
	btnm1_style_rel.body.grad_color = LV_COLOR_BLACK;
	btnm1_style_rel.body.border.color = LV_COLOR_SILVER;
	btnm1_style_rel.body.border.width = 1;
	btnm1_style_rel.body.border.opa = LV_OPA_50;
	btnm1_style_rel.body.radius = 0;

	/*Set button press style*/
	lv_style_copy(&btnm1_style_pr, &btnm1_style_rel);
	btnm1_style_pr.body.main_color = LV_COLOR_MAKE(0x55, 0x96, 0xd8);
	btnm1_style_pr.body.grad_color = LV_COLOR_MAKE(0x37, 0x62, 0x90);
	btnm1_style_pr.text.color = LV_COLOR_MAKE(0xbb, 0xd5, 0xf1);

	/*Set button inactive style*/
	lv_style_copy(&btnm1_style_ina, &lv_style_btn_ina);
	btnm1_style_ina.body.main_color = LV_COLOR_MAKE(0x8c, 0x8f, 0x91);
	btnm1_style_ina.body.grad_color = LV_COLOR_BLACK;
	btnm1_style_ina.body.border.color = LV_COLOR_SILVER;
	btnm1_style_ina.body.border.width = 1;
	btnm1_style_ina.body.border.opa = LV_OPA_50;
	btnm1_style_ina.body.radius = 0;

	/*Create a button matrix*/
	lv_obj_t * btnm1 = lv_btnm_create(left_page, NULL);
	lv_btnm_set_map(btnm1, btnm1_map);
	lv_btnm_set_action(btnm1, btnm_action_auton);
	lv_obj_set_size(btnm1, 220, 200);
	lv_btnm_set_style(btnm1, LV_BTNM_STYLE_BG, &btnm1_style_background);
	lv_btnm_set_style(btnm1, LV_BTNM_STYLE_BTN_PR, &btnm1_style_pr);
	lv_btnm_set_style(btnm1, LV_BTNM_STYLE_BTN_REL, &btnm1_style_rel);
	lv_btnm_set_style(btnm1, LV_BTNM_STYLE_BTN_INA, &btnm1_style_ina);

	/*Set up style for right page*/
	static lv_style_t right_page_style;
	lv_style_copy(&right_page_style, &lv_style_plain_color);
	right_page_style.body.main_color = LV_COLOR_BLACK;
	right_page_style.body.grad_color = LV_COLOR_RED;

	/*Set-up right page*/
	lv_obj_set_size(right_page, 240, 220);
	lv_obj_align(right_page, progress_bar, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 0);
	lv_obj_set_style(right_page, &right_page_style);

	/*Create a button descriptor array*/
	static const char * btnm2_map[] = {"\233Carlos", "\n",
																		"Rahul", "\n",
																		"Sam", "\n",
																		"Other",""};

	/*Create a button matrix*/
	lv_obj_t * btnm2 = lv_btnm_create(right_page, btnm1);
	lv_btnm_set_map(btnm2, btnm2_map);
	lv_btnm_set_action(btnm2, btnm_action_driver);

	/*Put anything that involves updating the menu here.*/
	/*
		TODO: Replace condition in the while loop
		Maybe something like !autonomous_is_done && !driver_is_done
	*/

	while(true){
		/*Update the value of the progress bar based on where the user is*/
		lv_bar_set_value(progress_bar, progress_bar_percentage);

		/*Update state of buttons*/

		/*Don't hog resources!*/
		pros::delay(2);
	}
}
