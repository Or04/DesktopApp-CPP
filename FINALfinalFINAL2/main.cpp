#include <iostream>
#include "./Control/Control.h"
#include "./Graphics/Graphics.h"
#include "./EventEngine/EventEngine.h"
#include "./Basic/Button/Button.h"
#include "./Basic/Label/Label.h"
#include "./Basic/Panel/Panel.h"
#include "./Basic/TextBox/TextBox.h"
#include "./Compound/CheckList/CheckList.h"
#include "./Compound/ComboBox/ComboBox.h"
#include "./Compound/NumericBox/NumericBox.h"
#include "./Compound/RadioBox/RadioBox.h"
using namespace std;

class SubmitListener : public MouseListener
{
private:
	Control &_c;

public:
	SubmitListener(Control &c) : _c(c) {}
	void MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_c.SetBackground(Color::Blue);
		_c.Show();
	}
};

class yesBtnListener : public MouseListener
{
private:
	Control &_c;

public:
	yesBtnListener(Control &c) : _c(c) {}
	void MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_c.SetBackground(Color::Black);
		_c.Hide();
	}
};

int main()
{
	Label labelRecipe(20);
	labelRecipe.SetValue("New recipe: ");
	Label labelIngredients(20);
	labelIngredients.SetValue("Ingredients:");
	Label labelCategory(20);
	labelCategory.SetValue("category:");
	Label labelKosher(20);
	labelKosher.SetValue("kosher:");
	Label labeLevel(20);
	labeLevel.SetValue("level:");
	Label labelTime(20);
	labelTime.SetValue("preparation time by minutes:");

	TextBox textboxRecipe(20);
	TextBox textboxIngredients(25);
	textboxIngredients.SetValue("butter,Sugar");

	Button buttonSubmit(15);
	buttonSubmit.SetValue("Start!!");
	CheckList checklistLevel(3, 15, {"beginner", "Advanced", "master"});
	checklistLevel.SelectIndex(1);
	NumericBox numBox(15, 18, 120);
	numBox.SetValue(18);
	ComboBox comboxC(30, {"Pastries", "Fish", "Meatֿֿֿֿֿֿֿ"});
	RadioBox radioK(3, 15, {"No", "Yes", "Not sure"});
	comboxC.SetSelectedIndex(1);
	Panel mainPanel(27, 55);
	mainPanel.addControl(labelRecipe, 1, 2);
	mainPanel.addControl(labelIngredients, 1, 5);
	mainPanel.addControl(labelCategory, 1, 8);
	mainPanel.addControl(labelKosher, 1, 11);
	mainPanel.addControl(labeLevel, 1, 15);
	mainPanel.addControl(labelTime, 1, 20);
	mainPanel.addControl(textboxRecipe, 25, 2);
	mainPanel.addControl(textboxIngredients, 25, 5);
	mainPanel.addControl(comboxC, 25, 8);
	mainPanel.addControl(radioK, 25, 11);
	mainPanel.addControl(checklistLevel, 25, 15);
	mainPanel.addControl(numBox, 25, 20);
	mainPanel.addControl(buttonSubmit, 25, 25);

	comboxC.SetBorder(BorderType::Single);
	labelRecipe.SetForeground(Color::Cyan);
	labelIngredients.SetForeground(Color::Cyan);
	labelCategory.SetForeground(Color::Cyan);
	labelKosher.SetForeground(Color::Cyan);
	labeLevel.SetForeground(Color::Cyan);
	labelTime.SetForeground(Color::Cyan);

	Control::setFocus(textboxRecipe);
	EventEngine engine;
	engine.run(mainPanel);

	return 1;
}
