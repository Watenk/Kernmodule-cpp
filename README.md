\--Photo--

### Release:

[Release Page](https://github.com/IvarNuij/Kernmodule-cpp/releases)

### About:

The game a simple shooter where you try to get the highest score possible. You shoot the enemy's that come your way and improve your score. But the higher your score is the faster, accurate,  the enemy's will be.

> Note: if you don't see the UI click on the maximize icon in the game window.

### Controls:

> **Moving     - W,A,S,D**
>
> **Shooting   - LMB**
>
> **Dashing     - Spacebar**
>
> **BulletBurst - E**

### Tweak the settings:

Check out [GlobalData.h](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/GlobalData.h)

### CodeStucture:

#####   
Math:

<details>
<summary>Collision</summary>

The collision is calculated in squares.
For more info see: [CollisionManager.cpp](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/CollisionManager.cpp)

</details>

<details>
<summary>Friction</summary>

See line function friction in: PhysicsObject.cpp

</details>

<details>
<summary>Vector2</summary>

See: [Vector2.cpp](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/Vector2.cpp)

</details>

<details>
<summary>Geometry</summary>

Calculating the velocity of a bullet: 

```
//Calc radian player to mouse
float distanceX = player->pos.x - mousePos.x;
float distanceY = player->pos.y - mousePos.y;  
float mouseRadian = std::atan2(distanceY, distanceX);

//calc Bullet Origin Point
player->playerBulletOrigin = watenk::Vector2(player->pos.x + playerBulletOriginRadius * -std::cos(mouseRadian), player->pos.y + playerBulletOriginRadius * -std::sin(mouseRadian));

//Calc BulletVelocity
watenk::Vector2 bulletNewton(-std::cos(mouseRadian) * bulletSpeed, -std::sin(mouseRadian) * bulletSpeed);
```

</details>


### Source Reference:

<https://www.sfml-dev.org/>

<https://stackoverflow.com/>

<https://www.w3schools.com/cpp/>

<https://cplusplus.com/>

<https://youtube.com>