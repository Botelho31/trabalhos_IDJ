#ifndef GAME_H
    #include "Game.h"
#endif

#ifndef GAMEOBJECT_H
    #define GAMEOBJECT_H
    #include "Rect.h"
    #include "Component.h"

    class State;
    
    class GameObject{
        public:
        
            GameObject();
            ~GameObject();
            void Update(float dt);
            void Render();
            bool IsDead();
            void Start();
            void RequestDelete();
            void AddComponent(Component* cpt);
            void RemoveComponent(Component* cpt);
            Component* GetComponent(std::string type);
            void NotifyCollision (GameObject& other);
            Rect box;
            bool started;
            double angleDeg; // SENTIDO HORARIO EM GRAUS
        private:
            std::vector<std::unique_ptr<Component>> components;
            bool isDead;

    };

#endif