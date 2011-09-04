/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
 * Copyright (C) 2011 MangosR2_ScriptDev2
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: boss_kiljaeden
SD%Complete:
SDComment:
SDCategory: Sunwell Plateau
EndScriptData */

#include "precompiled.h"
#include "sunwell_plateau.h"

enum UsedSpells
{
    // spells

    //Kilajden Spells
    // generic
    SPELL_TRANS                 = 23188, // Surprisingly, this seems to be the right spell.. (Where is it used?)
    SPELL_REBIRTH               = 44200, // Emerge from the Sunwell
    SPELL_DESTROY_DRAKES        = 46707,

    // phase 2
    SPELL_SOULFLY               = 45442,  // 9k Shadow damage over 3 seconds. Spammed throughout all the fight.
    SPELL_SOUL_FLAY_SLOW        = 47106,
    SPELL_LEGION_LIGHTING       = 45664,  // Chain Lightning, 4 targets, ~3k Shadow damage, 1.5fk mana burn
    SPELL_FIREBLOOM             = 45641,  // Places a debuff on 5 raid members, which causes them to deal 2k Fire damage to nearby allies and selves. MIGHT NOT WORK
    //SPELL_FIREBLOOM_EFF         = 45642, // 100% Damage

    // phase 3
    SPELL_SINISTER_REFLECTION   = 45892,
    //SPELL_SINISTER_REFLECTION = 45785, // Summon shadow copies of 5 raid members that fight against KJ's enemies//dont work
    SPELL_COPY_WEAPON           = 41055, // }
    SPELL_COPY_WEAPON2          = 41054, // }
    SPELL_COPY_OFFHAND          = 45206, // }- Spells used in Sinister Reflection creation
    SPELL_COPY_OFFHAND_WEAPON   = 45205, // }
    SPELL_SHADOW_SPIKE          = 46680,  // Bombard random raid members with Shadow Spikes (Very similar to Void Reaver orbs)
    SPELL_SHADOW_SPIKE_MISSLE   = 46589,
    SPELL_SHADOWSPIKE_EXP       = 45885, // 100% damage -> target self cast long range
    SPELL_SHADOWSPIKE_DEV       = 60851, // aoe 6k dmg
    SPELL_SHADOWSPIKE_VIS       = 33125, // visual effect

    //SPELL_FLAMEDART          = 45737, // Bombards the raid with flames every 3(?) seconds
    SPELL_FLAMEDART             = 45740,
    SPELL_DARKNESS_EXPLOSION    = 45657,
    SPELL_DARKNESS_OF_SOULS     = 46605,  // Begins a 8-second channeling, after which he will deal 50,000 damage to the raid

    // phase 4
    SPELL_ARMAGEDDON_TRIGG      = 45921,
    SPELL_ARMAGEDDON_VISUAL     = 45909,
    //SPELL_ARMAGEDDON_EFFECT     = 24207, // MIGHT BE CORRECT VISUAL
    SPELL_ARMAGEDDON_DMG        = 45915,
    SPELL_ARMAGEDDON_HELLFIRE   = 45911,
    SPELL_ARMAGEDDON_SPARK      = 45914,

/*  Armageddon spells wrong visual
    SPELL_ARMAGEDDON_TRIGGER                    = 45909, // Meteor spell trigger missile should cast Creature on himself
    SPELL_ARMAGEDDON_VISUAL                     = 45911, // Does the hellfire visual to indicate where the meteor missle lands
    SPELL_ARMAGEDDON_VISUAL2                    = 45914, // Does the light visual to indicate where the meteor missle lands
    SPELL_ARMAGEDDON_VISUAL3                    = 24207, // This shouldn't correct but same as seen on the movie
    SPELL_ARMAGEDDON_SUMMON_TRIGGER             = 45921, // Summons the triggers that cast the spells on himself need random target select
    SPELL_ARMAGEDDON_DAMAGE                     = 45915, // This does the area damage
*/

    // phase 5
    // Same spells with lower timers

    //Hand of the Deceiver Spells
    SPELL_FELLFIRE_PORTAL       = 46875,  // Creates a portal that spawns Felfire Fiends (LIVE FOR THE SWARM!1 FOR THE OVERMIND!)
    SPELL_SHADOWBOLT_VOLLEY     = 45770,  //~30 yard range Shadow Bolt Volley for ~2k(?) damage
    SPELL_SHADOW_INFUSION       = 45772,  // They gain this at 20% - Immunity to Stun/Silence and makes them look angry!
    SPELL_SHADOW_CHANNELING     = 46757,  // Channeling animation out of combat
    //SPELL_IMPFUSION             = 45779, // 100%
    SPELL_SUMMON_FELFIRE_FIEND  = 46464,

    // Felfire fiend
    SPELL_FELFIRE_FISSION       = 45779,   // Felfire Fiends explode when they die or get close to target.

    // Anveena
    SPELL_ANVEENA_PRISON        = 46367,  // She hovers locked within a bubble
    SPELL_ANVEENA_DRAIN         = 46410,  // Sunwell energy glow animation (Control mob uses this)
    SPELL_SUNWELL_IGNITION      = 46822,
    SPELL_SACRIFICE_OF_ANVEENA  = 46474,  // This is cast on Kil'Jaeden when Anveena sacrifices herself into the Sunwell
    SPELL_ENTROPIUS_BODY        = 46819,  // Visual for Entropius at the Epilogue
    SPELL_CALL_ENTROPIUS        = 46818,

    //Orb Spells
    SPELL_SHADOW_ORB_BOLT_TRIGG = 45679,
    //SPELL_ORB_BOLT_DEV          = 45680,
    //SPELL_ORB_BOLT              = 53086,
    //SPELL_SHADOW_BOLT           = 45680,  //45679 would be correct but triggers to often //TODO fix console error

    //Reflections Spells  TODO
    SPELL_PRIEST                = 47077,  // HOLY_SMITE
    SPELL_PRIEST2               = 47079,  // RENEW

    SPELL_PALADIN               = 38921,  // HOLY_SHOCK
    SPELL_PALADIN2              = 37369,  // HAMMER_OF_JUSTICE

    SPELL_WARLOCK               = 46190,  // CURSE_OF_AGONY
    SPELL_WARLOCK2              = 47076,  // SHADOW_BOLT

    SPELL_MAGE                  = 47074,  // FIREBALL

    SPELL_ROGUE                 = 45897,  // HEMORRHAGE

    SPELL_WARRIOR               = 17207,  // WHIRLWIND

    SPELL_DRUID                 = 47072,  // MOONFIRE

    SPELL_SHAMAN                = 47071,  // EARTH_SHOCK

    SPELL_HUNTER                = 48098,  // MULTI_SHOT
    SPELL_HUNTER2               = 16496,  // SHOOT
    SPELL_HUNTER3               = 40652,  // WING_CLIP

    // USED BY BLUE ORB
    SPELL_VENGEANCE_OF_THE_BLUE_FLIGHT  = 45839, // Possess the blue dragon from the orb to help the raid.
    SPELL_RING_OF_BLUE_FLAMES           = 45825  //Cast this spell when the go is activated
    //SPELL_REVITALIZE            = 45027, // 100%
    //SPELL_SHIELD_OF_BLUE        = 45848, // 100%
    //AURA_BLUESHIELD             = 44867, // :D
    //SPELL_HASTE                 = 45856, // NOT WORKING
};

enum Npcs_Go
{
    //NPC_ANVEENA         = 26046, // Embodiment of the Sunwell
    //NPC_KALECGOS        = 25319, // Helps the raid throughout the fight
    NPC_BLUE_DRAGON     = 25653, // controlled by players
    NPC_VELEN           = 26246, // outro
    NPC_LIADRIN         = 26247, // outro
    NPC_VELEN_PORTAL    = 24925,
    NPC_CORE_ENTROPIUS  = 26262, // Used in the ending cinematic?

    // encounter
    NPC_DECIVER         = 25588,
    NPC_FELFIRE_PORTAL  = 25603,
    NPC_SHIELD_ORB      = 25502,
    NPC_SINISTER        = 25708, // Sinister Reflection
    NPC_ARMAGEDON       = 25735,
    NPC_FELFIRE_FIEND   = 25598,
    NPC_SHADOWSPIKE     = 30598,

    // objects
    NPC_BLUE_ORB_TARGET = 25640,
    ORB_BLUE_DRAGONFLIGHT  = 188415,
};

enum Texts
{
/*** Speech and sounds***/
    // These are used throughout Sunwell and Magisters(?). Players can hear this while running through the instances.
    SAY_OFFCOMBAT1                          = -1580064,
    SAY_OFFCOMBAT2                          = -1580065,
    SAY_OFFCOMBAT3                          = -1580066,
    SAY_OFFCOMBAT4                          = -1580067,
    SAY_OFFCOMBAT5                          = -1580068,

    // Encounter speech and sounds
    SAY_EMERGE                              = -1580069,
    SAY_SLAY1                               = -1580070,
    SAY_SLAY2                               = -1580071,
    SAY_REFLECTION1                         = -1580072,
    SAY_REFLECTION2                         = -1580073,
    SAY_DARKNESS1                           = -1580074,
    SAY_DARKNESS2                           = -1580075,
    SAY_DARKNESS3                           = -1580076,
    SAY_PHASE_FOUR	                        = -1580077,
    SAY_PHASE_THREE                         = -1580078,
    SAY_PHASE_FIVE	                        = -1580079,

    // Kalecgos - Anveena speech
    SAY_KALECGOS_INTRO                      = -1580080,
    // phase 3
    SAY_KALECGOS_AWAKEN                     = -1580081,
    SAY_ANVEENA_IMPRISONED                  = -1580082,
    // phase 4
    SAY_KALECGOS_LETGO                      = -1580083,
    SAY_ANVEENA_LOST                        = -1580084,
    // phase 5
    SAY_KALECGOS_FOCUS                      = -1580085,
    SAY_ANVEENA_KALEC                       = -1580086,
    SAY_KALECGOS_FATE                       = -1580087,
    SAY_ANVEENA_GOODBYE                     = -1580088,
    SAY_KALECGOS_GOODBYE                    = -1580089,
    SAY_KALECGOS_ENCOURAGE                  = -1580090,

    // orbs
    SAY_KALECGOS_ORB1                       = -1580091,
    SAY_KALECGOS_ORB2                       = -1580092,
    SAY_KALECGOS_ORB3                       = -1580093,
    SAY_KALECGOS_ORB4                       = -1580094,

    /*** Outro Sounds***/
    SAY_OUTRO_01_VELEN   = -1580095,
    SAY_OUTRO_02_VELEN   = -1580096,
    SAY_OUTRO_03_VELEN   = -1580097,
    SAY_OUTRO_04_VELEN   = -1580098,
    SAY_OUTRO_05_LIADRIN = -1580099,
    SAY_OUTRO_06_VELEN   = -1580100,
    SAY_OUTRO_07_LIADRIN = -1580101,
    SAY_OUTRO_08_VELEN   = -1580102,
    SAY_OUTRO_09_VELEN   = -1580103,
    SAY_OUTRO_10_LIADRIN = -1580104,
    SAY_OUTRO_11_VELEN   = -1580105,
    SAY_OUTRO_12_VELEN   = -1580106,
    SAY_OUTRO_13_VELEN   = -1580107,
};

enum Phazes
{
    PHASE_IDLE  = 0,  // phase which kil jaedan is yelling awhile players goes thur instance
    PHASE_ONE   = 1,  //  unsure how im gonna use this might have to rewrite the phase layout
    PHASE_TWO   = 2,
    PHASE_THREE = 3,
    PHASE_FOUR  = 4,
    PHASE_FIVE  = 5,
    PHASE_OUTRO = 6,
};

uint8 m_uiDecieverDead;

/*######
## boss_kiljaeden
######*/

struct MANGOS_DLL_DECL boss_kiljaedenAI : public Scripted_NoMovementAI
{
    boss_kiljaedenAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
        Reset();
    }

    ScriptedInstance* m_pInstance;

    // Phase Idle
    uint32 m_uiOrdersTimer;

    // Phase One
    
    