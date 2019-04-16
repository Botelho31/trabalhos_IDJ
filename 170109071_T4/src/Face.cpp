#include "../include/Face.h"
#include "../include/Sound.h"
#include "../include/InputManager.h"
#include "../include/Camera.h"

    Face::Face(GameObject& associated) : Component(associated){
        hitpoints = 30;
        isDying = false;
    }

    Face::~Face(){
        
    }

    void Face::Damage(int damage){
        hitpoints -= damage;
        if((hitpoints <= 0) && (isDying == false)){
            Component *component = associated.GetComponent("Sound");
            if(component != nullptr){
                Sound *sound = dynamic_cast<Sound*>(component);
                sound->Play(1);
                isDying = true;
                SDL_TimerID timerid =  SDL_AddTimer(800,DelayedDeath,&associated);
            }else{
                associated.RequestDelete();
            }
        }
    }

    Uint32 Face::DelayedDeath(Uint32 interval, void *param){
        GameObject* game =  static_cast<GameObject*>(param);
        game->RequestDelete();
        return 0;
    }

    void Face::Update(float dt){
        InputManager *input =  &(InputManager::GetInstance());
        if(input->MousePress(SDL_BUTTON_LEFT) == true){
            if(associated.box.Contains( ((float)input->GetMouseX() + Camera::pos.x), ((float)input->GetMouseY() + Camera::pos.y)) ){
                // std::cout << "Sprite X: " << associated.box.x << " Sprite Y: "<< associated.box.y << std::endl;
                // std::cout << "Camera X: " << Camera::pos.x << " Camera Y: "<< Camera::pos.y << std::endl;
                // std::cout << "Mouse X: " << input->GetMouseX() << " Mouse Y: "<< input->GetMouseY() << std::endl << std::endl;
                Damage(std::rand() % 10 + 10);
            }
        }
    }

    void Face::Render(){

    }

    bool Face::Is(std::string type){
        if(type == "Face"){
            return true;
        }else{
            return false;
        }
    }