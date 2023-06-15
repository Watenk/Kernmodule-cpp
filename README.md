![game screenshot!](/READMEFiles/GameScreenshot.jpg)

### Release:

[Release Page](https://github.com/IvarNuij/Kernmodule-cpp/releases)

### About:

The game a simple shooter where you try to get the highest score possible. You shoot the enemy's that come your way and improve your score. But the higher your score is the faster, accurate and stronger the enemy's will be.

> Note: if you don't see the UI ingame click on the maximize icon in the game window.

::: warn
Your antivirus can be triggered by the game build because the game directly reads your keyboard keys and thinks it's a keylogger.

:::

### Controls:

- **Moving     - W,A,S,D**
- **Shooting   - LMB**
- **Dashing     - Spacebar**
- **BulletBurst - E**

### Tweak the settings:

Check out [GlobalData](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/GlobalData.h)

### CodeStucture:

- The [GameManager](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/GameManager.cpp) keeps track and updates all the other managers and [baseclasses](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/BaseClass.cpp) in the game. Every script that needs to be constantly updated inherits from the [baseclass](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/BaseClass.cpp) class.
- The most important script after the [GameManager](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/GameManager.cpp) is the [SceneManager](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/SceneManager.cpp). The [SceneManager](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/SceneManager.cpp) contolls what appears in each scene.
- All objects with physics (Friction, collision, etc) inherit from [PhysicsObject](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/PhysicsObject.cpp).
- All the game consts are in the [GlobalData ](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/GlobalData.h)header.

### Math:

<details>
<summary>Collision</summary>

The collision is calculated in squares around each [PhysicsObject](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/PhysicsObject.cpp). 

![Debug screenshot!](/READMEFiles/DebugScreenshot.jpg)

When 2 objects collide they take damage based on the force in newton, the velocity and position is calculated after that.

For more info see: [CollisionManager](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/CollisionManager.cpp)

</details>

<details>
<summary>Friction</summary>

First the normalforce is calculated and if the object is static the staticFrictionCoefficient will be applied. If the object isn't static the kineticFrictionCoefficient will be applied. After that the fore will be converted to velocity and is applied on the object.

For more info see: [PhysicsObject](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/PhysicsObject.cpp#L79)

</details>

<details>
<summary>Vector2</summary>

See: [Vector2](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/Vector2.cpp)

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

</details>

<summary>Time</summary>

The TimeManager calculates the frameTime, frameRate, upsTime and deltaTime.

For more info see: [TimeManager](https://github.com/IvarNuij/Kernmodule-cpp/blob/main/kernmodule-cpp/TimeManager.cpp)

</details>

### Build The Game:

1. Pull the source code
2. Link the SFML library (See: [SFML / Learn](https://www.sfml-dev.org/tutorials/2.5/start-vc.php))

### Source References:

<https://www.sfml-dev.org/>

<https://stackoverflow.com/>

<https://www.w3schools.com/cpp/>

<https://cplusplus.com/>