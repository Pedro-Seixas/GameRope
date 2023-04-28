#include "Menu.h"


Menu::Menu(sf::Vector2f startPosition, sf::Vector2f size)
{
    //Adjust buttons position
    sf::Vector2f startButtonPosition(startPosition.x, startPosition.y - 100);
    sf::Vector2f aboutButtonPosition(startPosition.x, startPosition.y + 50);
    sf::Vector2f quitButtonPosition(startPosition.x, startPosition.y + 200);
    sf::Vector2f titlePosition(startPosition.x - 40.f, startPosition.y - 270);

    //Create buttons
    buttons = std::make_unique<Button[]>(3);

    //Load image and scale.
    buttons[0].normalButton.loadFromFile("img/Start.png");
    buttons[0].selectedButton.loadFromFile("img/Start_Selected.png");
    buttons[0].selectedButton.setSmooth(true);
    buttons[0].normalButton.setSmooth(true);
    buttons[0].buttonSprite.setTexture(buttons[0].normalButton);
    buttons[0].buttonSprite.setPosition(startButtonPosition);
    buttons[0].buttonSprite.setScale(0.5f, 0.5f);


    buttons[1].normalButton.loadFromFile("img/About.png");
    buttons[1].selectedButton.loadFromFile("img/About_Selected.png");
    buttons[1].selectedButton.setSmooth(true);
    buttons[1].normalButton.setSmooth(true);
    buttons[1].buttonSprite.setTexture(buttons[1].normalButton);
    buttons[1].buttonSprite.setPosition(aboutButtonPosition);
    buttons[1].buttonSprite.setScale(0.5f, 0.5f);

    buttons[2].normalButton.loadFromFile("img/Quit.png");
    buttons[2].selectedButton.loadFromFile("img/Quit_Selected.png");
    buttons[2].selectedButton.setSmooth(true);
    buttons[2].normalButton.setSmooth(true);
    buttons[2].buttonSprite.setTexture(buttons[2].normalButton);
    buttons[2].buttonSprite.setPosition(quitButtonPosition);
    buttons[2].buttonSprite.setScale(0.5f, 0.5f);

    //Title
    titleTexture.loadFromFile("img/Rope.png");
    titleTexture.setSmooth(true);
    titleSprite.setTexture(titleTexture);
    titleSprite.setPosition(titlePosition);
    titleSprite.setScale(0.7f, 0.7f);

}

void Menu::drawMenu(sf::RenderWindow& window) {
    for (int i = 0; i < 3; i++) {
        window.draw(buttons[i].buttonSprite);
    }
    window.draw(titleSprite);
}

void Menu::update(sf::RenderWindow& window) {

    int buttonNumber = 0;
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosView = window.mapPixelToCoords(mousePos);

    for (int i = 0; i < 3; i++) {
        if (buttons[i].buttonSprite.getGlobalBounds().contains(mousePosView)) {
            buttons[i].buttonSprite.setTexture(buttons[i].selectedButton);
            buttonNumber = i;
            break;
        }
        else {
            buttons[i].buttonSprite.setTexture(buttons[i].normalButton);
        }
    }

    if (buttons[buttonNumber].buttonSprite.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        buttonSelection = buttonNumber;
        getButtonSelection();
    }

}

int Menu::getButtonSelection()
{
    std::cout << buttonSelection << std::endl;
    return buttonSelection;
}

void Menu::setButtonSelection(int button)
{
    buttonSelection = button;
}