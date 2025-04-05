# Tower Defense Game

![Screenshot 2025-04-05 160148](https://github.com/user-attachments/assets/ed154c02-fbb0-4621-a529-e7461c94ec9d)


This is a Tower Defense game project built using SFML (Simple and Fast Multimedia Library). The game involves placing different types of towers on a grid to defend against waves of critters. The game uses several design patterns to handle its various functionalities.

## Design Patterns Used

### 1. **Strategy Pattern**
The **Strategy pattern** is used to handle the different targeting strategies for the towers. Each tower can have a different targeting behavior based on its type. The Strategy pattern allows the dynamic switching of targeting strategies at runtime, allowing for flexibility and easier extension of new targeting behaviors.

- **Targeting Strategies:**
  - `NearestToTowerStrategy`: Targets the nearest critter to the tower.
  - `WeakestCritterStrategy`: Targets the critter with the lowest health.
  - `StrongestCritterStrategy`: Targets the critter with the highest health.
  - `NearestToExitStrategy`: Targets the critter nearest to the exit.

Each tower is assigned a targeting strategy that defines how it chooses which critter to attack. This strategy can be changed based on user actions or game progress, providing a flexible and extensible system for targeting behavior.

### 2. **Observer Pattern**
The **Observer pattern** is used for the `Tower` and `Critter` entities. In this case, `TowerView` and `CritterView` observe changes in the `Tower` and `Critter` objects and update the display accordingly. The observer pattern helps keep the UI synchronized with the game state.

- **TowerObserver:** Observes changes in towers, such as upgrades or state changes.
- **CritterObserver:** Observes critters' health and movement, updating the display with the latest information.

### 3. **Decorator Pattern**
The **Decorator pattern** is used to add additional functionality to towers dynamically. This allows for towers to be enhanced with new abilities without modifying their core structure.

- **Tower Decorators:**
  - `LevelUpgradeDecorator`: Increases the tower’s level and power.
  - `FreezingEffectDecorator`: Adds a freezing effect to slow down critters.
  - `SplashDamageDecorator`: Adds splash damage to towers, affecting multiple critters at once.
  - `BurningDamageDecorator`: Adds a burning effect to damage critters over time.

These decorators can be applied to towers to enhance their functionality, allowing for a flexible and extendable system.

### 4. **Factory Method Pattern**
The **Factory Method pattern** is used to create critters dynamically. Depending on the wave or the game conditions, the `CritterFactory` generates different types of critters, such as `GoblinCritter` and `OgreCritter`. This pattern allows for easy extension when adding new types of critters.

### 5. **Singleton Pattern**
The **Singleton pattern** is used for the game’s `Map` object. This ensures that there is only one instance of the map throughout the game. The map maintains the game grid, stores the placement of towers, and manages the cells' types (e.g., scenery, path, entry, exit).

### 6. **Command Pattern**
The **Command pattern** is used for the player's actions, such as placing a tower, upgrading a tower, or interacting with the grid. Each action is encapsulated as an object, allowing for undo/redo functionality and easier extension of additional player actions.


