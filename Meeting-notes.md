
- Weeks Meetings
    - November 6, 2023

        Participans
        -Nandu
        -Noel
        -Akseli
        -Niilo
        
        The following topics were discussed at the meeting
        
        - Map tiles implementation and we discussed about how to use them
        - What kind of coordinate system should the game use? (tiles ,x and y coordinates or SFML global coords)
        - Enemy properties (hp, speed, special attributes?)
        - Tower properties (range, damage, cost, special ability)
        - Use of git, everyone does their own branch and then we merge them in our weekly meetings
        - Shared topics to work on until next meeting (moving enemy, placing towers, attacking)
    - November 13, 2023

        Participans
        -Nandu
        -Noel
        -Akseli
        -Niilo

        - Merged our own development branches, now we have a running enemy and 3 types of towers can be placed. (Towers do nothing)
        - We discussed about enemy and tower structure
        - Game graphics update, enemies and towers vectors created. They are used in drawing the enemies and towers
        - Logic for paths
        - How do delete and deal with dead enemies.
        - How shooting the enemies actually works. Something like this:
        
            for each tower in towers:
                for each enemy in enemies:
                    if distance(tower, enemy) < tower.range:
                        if time since last attack >= tower.attack_speed:
                            enemy.health -= tower.damage
                            if enemy.health <= 0:
                                destroy enemy
                            reset time since last attack
    - November 20, 2023

        Participans
        -Nandu
        -Noel
        -Akseli
        -Niilo

        -Merged our weekly work with git
        -New stuff added: main menu, multiple enemies running through the path, game states
        -Did some debugging
        -We set new goals for the next week: attacking, time keeping, money system(killing enemies and creating towers), different enemies, losing screen, game states for building and attacking.

    -November 22, 2023

        Participans
        -Nandu
        -Noel
        -Akseli
        -Niilo

        -New stuff added: towers shoot and have ranges, different types of enemies, losing screen, start of money system
        -Merged our codes
        -Set new goals: Special attakcs for towers, continue developing time and money system, implement rounds
    - December 4, 2023

        Participans
        -Nandu
        -Noel
        -Akseli
        -Niilo

        -New stuff added, towers shoot only the 1st enemy for each timestep, endless rounds with increasing difficulty,
            resetting the game after the game has ended.
        -Merged the codes
        -Test run for merged project, successful
        -Plans for final week: Money system and capability to choose the game difficulty in the main menu.
    -December 8, 2023

        Participans
        -Nandu
        -Noel
        -Niilo

        -Final edits made before Demo, Discussed what to implement after
        -Round implemented and money system finished
        -Multiple paths implemented
        
