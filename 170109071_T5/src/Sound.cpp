#include "../include/Sound.h"

Sound::Sound(GameObject& associated) : Component(associated){
    chunk = nullptr;
    channel = -2;
}

Sound::Sound(GameObject& associated, std::string file) : Sound(associated){
    Open(file);
}

Sound::~Sound(){
    if(chunk != nullptr){
        if(channel != -2){
            Mix_HaltChannel(channel);
        }
    }
}

void Sound::Open(std::string file){
    chunk = Resources::GetSound(file);
    if(chunk == nullptr){
        std::cout << "Failed to load Sound: " << SDL_GetError() << std::endl;
    }
}

void Sound::Play(int times){
    channel = Mix_PlayChannel(-1,chunk,times);
}

bool Sound::IsPlaying(){
    if(Mix_Playing(channel)){
        return true;
    }else{
        return false;
    }
}

bool Sound::IsOpen(){
    if(chunk){
        return true;
    }else{
        return false;
    }
}

void Sound::Stop(){
    if(chunk != nullptr){
        Mix_HaltChannel(channel);
    }
}

void Sound::Update(float dt){

}

void Sound::Render(){

}

bool Sound::Is(std::string file){
    if(file == "Sound"){
        return true;
    }else{
        return false;
    }
}
