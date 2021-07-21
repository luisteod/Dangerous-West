#include "Personagem.hpp"

Personagem::Personagem(sf::Vector2f Pos, sf::Vector2f Vel, const char *caminhoTextura) :
text(NULL) , position(Pos) , velocity(Vel) 
{
    //corpo.setPosition(sf::Vector2f(100 , 100));
     
    cout<<"carregando text"<<endl;
    text = new sf::Texture();
    
    if (!text->loadFromFile(caminhoTextura))
    {
       cout << "Nao carregou a textura" << endl;
    }

    cout<<"carregou text"<<endl;

    /* Coloca textura no retangulo */
    corpo.setTexture(text);
    /* Atribui o tamanho do retangulo */
    corpo.setSize(sf::Vector2f(100.0f, 100.0f));
   
    corpo.setOrigin(corpo.getSize() / 2.0f);
}
Personagem::~Personagem()
{
    if(text) delete text;
}
void Personagem::atualizar(float t)
{
    position += velocity*t;

    corpo.setPosition(position);
}
void Personagem::desenhar(sf::RenderWindow *janela)
{
   janela->draw(corpo);
}