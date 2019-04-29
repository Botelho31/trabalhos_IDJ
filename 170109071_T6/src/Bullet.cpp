#include "../include/Bullet.h"
#include "../include/Sprite.h"
#include "../include/Collider.h"

Bullet::Bullet(GameObject& associated,float angle,float speed,int damage,float maxDistance,std::string sprite,int frameCount,float frameTime,bool targetsPlayer) : 
    Component(associated){
        Sprite *bullet = new Sprite(associated,sprite,frameCount,frameTime);
        Collider *collider = new Collider(associated);
        associated.AddComponent(collider);        
        associated.AddComponent(bullet);
        associated.angleDeg = -((angle * 180)/PI);
        this->speed.x = speed;
        this->speed.y = speed;
        this->distanceLeft = maxDistance;
        this->damage = damage;
        this->angle = angle;
        this->targetsPlayer = targetsPlayer;
}

void Bullet::NotifyCollision(GameObject& other){
    Component *component =  other.GetComponent("PenguinBody");
    Component *component2 =  other.GetComponent("PenguinCannon");
    Component *component3 =  other.GetComponent("Alien");
    if(component){
        if (targetsPlayer){
            associated.RequestDelete();
        }
    }
    if(component2){
        if(targetsPlayer){
            associated.RequestDelete();
        }
    }
    if(component3){
        if (!(targetsPlayer)){
            associated.RequestDelete();
        }
    }
}

void Bullet::Update(float dt){
    associated.box.x += (cos(angle) * speed.x) * dt;
    associated.box.y += ((-sin(angle)) * speed.y) * dt;
    distanceLeft -= fabs((((-sin(angle)) * speed.y) * dt))  + fabs(((cos(angle) * speed.x) * dt));
    if(distanceLeft <= 0){
        associated.RequestDelete();
    }
}

void Bullet::Render(){

}

bool Bullet::Is(std::string type){
    if(type == "Bullet"){
        return true;
    }else{
        return false;
    }
}

int Bullet::GetDamage(){
    return damage;
}

