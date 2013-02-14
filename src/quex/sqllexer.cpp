#include "sqllexer"
#include <quex/code_base/analyzer/C-adaptions.h>
QUEX_NAMESPACE_MAIN_OPEN
/* Global */QUEX_NAME(Mode)  QUEX_NAME(ONE_AND_ONLY);
#ifndef __QUEX_INDICATOR_DUMPED_TOKEN_ID_DEFINED
    static QUEX_TYPE_TOKEN_ID    QUEX_NAME_TOKEN(DumpedTokenIdObject);
#endif
#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
#define __self_result_token_id    QUEX_NAME_TOKEN(DumpedTokenIdObject)

void
QUEX_NAME(ONE_AND_ONLY_on_entry)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* FromMode) {
    (void)me;
    (void)FromMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(ONE_AND_ONLY).has_entry_from(FromMode);
#   endif

}

void
QUEX_NAME(ONE_AND_ONLY_on_exit)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* ToMode)  {
    (void)me;
    (void)ToMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(ONE_AND_ONLY).has_exit_to(ToMode);
#   endif

}

#if defined(QUEX_OPTION_INDENTATION_TRIGGER) 
void
QUEX_NAME(ONE_AND_ONLY_on_indentation)(QUEX_TYPE_ANALYZER*    me, 
                                        QUEX_TYPE_INDENTATION  Indentation, 
                                        QUEX_TYPE_CHARACTER*   Begin) {
    (void)me;
    (void)Indentation;
    (void)Begin;
    return;
}
#endif

#ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
bool
QUEX_NAME(ONE_AND_ONLY_has_base)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return false;
}
bool
QUEX_NAME(ONE_AND_ONLY_has_entry_from)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return true; /* default */
}
bool
QUEX_NAME(ONE_AND_ONLY_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return false;
}
#endif    
#undef self
#undef __self_result_token_id
QUEX_NAMESPACE_MAIN_CLOSE

/* #include "sqllexer"*/
QUEX_NAMESPACE_MAIN_OPEN
QUEX_TYPE_CHARACTER  QUEX_LEXEME_NULL_IN_ITS_NAMESPACE = (QUEX_TYPE_CHARACTER)0;

#include <quex/code_base/analyzer/member/basic>
#include <quex/code_base/buffer/Buffer>
#ifdef QUEX_OPTION_TOKEN_POLICY_QUEUE
#   include <quex/code_base/token/TokenQueue>
#endif

#ifdef    CONTINUE
#   undef CONTINUE
#endif
#define   CONTINUE goto __REENTRY_PREPARATION; 

#ifdef    RETURN
#   undef RETURN
#endif

#if defined(QUEX_OPTION_TOKEN_POLICY_QUEUE)
#   define RETURN   return
#else
#   define RETURN   do { return __self_result_token_id; } while(0)
#endif
#include <quex/code_base/temporary_macros_on>

__QUEX_TYPE_ANALYZER_RETURN_VALUE  
QUEX_NAME(ONE_AND_ONLY_analyzer_function)(QUEX_TYPE_ANALYZER* me) 
{
    /* NOTE: Different modes correspond to different analyzer functions. The analyzer  
             functions are all located inside the main class as static functions. That  
             means, they are something like 'globals'. They receive a pointer to the   
             lexical analyzer, since static member do not have access to the 'this' pointer.
     */
#   if defined(QUEX_OPTION_TOKEN_POLICY_SINGLE)
    register QUEX_TYPE_TOKEN_ID __self_result_token_id 
           = (QUEX_TYPE_TOKEN_ID)__QUEX_SETTING_TOKEN_ID_UNINITIALIZED;
#   endif
#   ifdef     self
#       undef self
#   endif
#   define self (*((QUEX_TYPE_ANALYZER*)me))
    QUEX_TYPE_CHARACTER_POSITION   position[1]                    = { 0};
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = ((QUEX_TYPE_CHARACTER)0x0);
    const size_t                   PositionRegisterN              = (size_t)1;
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_index             = ((QUEX_TYPE_CHARACTER)0x0);
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */
#   define ONE_AND_ONLY    (QUEX_NAME(ONE_AND_ONLY))

    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE) \
       || defined(QUEX_OPTION_ASSERTS)
    me->DEBUG_analyzer_function_at_entry = me->current_analyzer_function;
#   endif
__REENTRY:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
INIT_STATE_TRANSITION_BLOCK:
    input = *(me->buffer._input_p);
    __quex_debug("Init State\n");
    __quex_debug_state(437);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(437, 488);

        case 0x9: 
        case 0xA: 
        case 0xD: 
        case 0x20: goto _440;

        case 0x22: goto _451;

        case 0x2A: goto _439;

        case 0x2D: goto _444;

        case 0x2F: goto _448;

        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _438;

        case 0x3B: goto _445;

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: goto _449;

        case 0x64: goto _446;

        case 0x65: goto _443;

        case 0x66: 
        case 0x67: 
        case 0x68: goto _449;

        case 0x69: goto _441;

        case 0x6A: goto _442;

        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: goto _449;

        case 0x73: goto _447;

        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

        case 0x7B: goto _450;

        case 0x7D: goto _452;

    }
    __quex_debug_drop_out(437);
    
    goto _490; /* TERMINAL_FAILURE */


_437: /* (437 from NONE) */


    ++(me->buffer._input_p);
    goto INIT_STATE_TRANSITION_BLOCK;


    __quex_assert_no_passage();
_449: /* (449 from 449) (449 from 447) (449 from 462) (449 from 465) (449 from 466) (449 from 463) (449 from 464) (449 from 469) (449 from 470) (449 from 467) (449 from 468) (449 from 473) (449 from 474) (449 from 471) (449 from 472) (449 from 477) (449 from 478) (449 from 481) (449 from 482) (449 from 479) (449 from 480) (449 from 485) (449 from 486) (449 from 483) (449 from 484) (449 from 437) (449 from 441) (449 from 442) (449 from 446) (449 from 443) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(449);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(449, 491);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_491:
    __quex_debug_drop_out(449);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_492: /* (459 from 455) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_459: /* (459 from 459) (459 from 460) (459 from 458) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(459);
    if( input < 0x2A ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD_FORWARD(459, 493);

            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: 
            case 0xA: 
            case 0xB: 
            case 0xC: 
            case 0xD: 
            case 0xE: 
            case 0xF: 
            case 0x10: 
            case 0x11: 
            case 0x12: 
            case 0x13: 
            case 0x14: 
            case 0x15: 
            case 0x16: 
            case 0x17: 
            case 0x18: 
            case 0x19: 
            case 0x1A: 
            case 0x1B: 
            case 0x1C: 
            case 0x1D: 
            case 0x1E: 
            case 0x1F: 
            case 0x20: 
            case 0x21: 
            case 0x22: 
            case 0x23: 
            case 0x24: 
            case 0x25: 
            case 0x26: 
            case 0x27: 
            case 0x28: 
            case 0x29: goto _459;

        }
    } else {

        if( input == 0x2A ) {
            goto _458;

        } else if( input < 0x110000 ) {
            goto _459;

        } else {

}    }_493:
    __quex_debug_drop_out(459);
    me->buffer._input_p = position[0];
    goto TERMINAL_93;


    __quex_assert_no_passage();
_451: /* (451 from 451) (451 from 437) (451 from 453) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(451);
    if( input < 0x23 ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD_FORWARD(451, 494);

            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: 
            case 0xA: 
            case 0xB: 
            case 0xC: 
            case 0xD: 
            case 0xE: 
            case 0xF: 
            case 0x10: 
            case 0x11: 
            case 0x12: 
            case 0x13: 
            case 0x14: 
            case 0x15: 
            case 0x16: 
            case 0x17: 
            case 0x18: 
            case 0x19: 
            case 0x1A: 
            case 0x1B: 
            case 0x1C: 
            case 0x1D: 
            case 0x1E: 
            case 0x1F: 
            case 0x20: 
            case 0x21: goto _451;

            case 0x22: goto _454;

        }
    } else {

        if( input < 0x5C ) {
            goto _451;

        } else if( input == 0x5C ) {
            goto _453;

        } else if( input < 0x110000 ) {
            goto _451;

        } else {

}    }_494:
    __quex_debug_drop_out(451);
    
    goto _490; /* TERMINAL_FAILURE */


    __quex_assert_no_passage();
_440: /* (440 from 440) (440 from 437) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(440);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(440, 495);

        case 0x9: 
        case 0xA: 
        case 0xD: 
        case 0x20: goto _440;

    }
_495:
    __quex_debug_drop_out(440);
    goto TERMINAL_4;


    __quex_assert_no_passage();
_456: /* (456 from 448) (456 from 456) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(456);
    if( input < 0xA ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD_FORWARD(456, 496);

            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: goto _456;

        }
    } else {

        if( input == 0xA ) {
            goto _457;

        } else if( input < 0x100 ) {
            goto _456;

        } else {

}    }_496:
    __quex_debug_drop_out(456);
    
    goto _490; /* TERMINAL_FAILURE */


    __quex_assert_no_passage();
_475: /* (475 from 475) (475 from 444) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(475);
    if( input < 0xA ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD_FORWARD(475, 497);

            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: goto _475;

        }
    } else {

        if( input == 0xA ) {
            goto _476;

        } else if( input < 0x100 ) {
            goto _475;

        } else {

}    }_497:
    __quex_debug_drop_out(475);
    
    goto _490; /* TERMINAL_FAILURE */


    __quex_assert_no_passage();
_498: /* (458 from 455) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_458: /* (458 from 459) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(458);
    if( input < 0x2B ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD_FORWARD(458, 499);

            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: 
            case 0xA: 
            case 0xB: 
            case 0xC: 
            case 0xD: 
            case 0xE: 
            case 0xF: 
            case 0x10: 
            case 0x11: 
            case 0x12: 
            case 0x13: 
            case 0x14: 
            case 0x15: 
            case 0x16: 
            case 0x17: 
            case 0x18: 
            case 0x19: 
            case 0x1A: 
            case 0x1B: 
            case 0x1C: 
            case 0x1D: 
            case 0x1E: 
            case 0x1F: 
            case 0x20: 
            case 0x21: 
            case 0x22: 
            case 0x23: 
            case 0x24: 
            case 0x25: 
            case 0x26: 
            case 0x27: 
            case 0x28: 
            case 0x29: goto _459;

            case 0x2A: goto _460;

        }
    } else {

        if( input < 0x2F ) {
            goto _459;

        } else if( input == 0x2F ) {
            goto _461;

        } else if( input < 0x110000 ) {
            goto _459;

        } else {

}    }_499:
    __quex_debug_drop_out(458);
    me->buffer._input_p = position[0];
    goto TERMINAL_93;


    __quex_assert_no_passage();
_460: /* (460 from 460) (460 from 458) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(460);
    if( input < 0x2B ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD_FORWARD(460, 500);

            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: 
            case 0xA: 
            case 0xB: 
            case 0xC: 
            case 0xD: 
            case 0xE: 
            case 0xF: 
            case 0x10: 
            case 0x11: 
            case 0x12: 
            case 0x13: 
            case 0x14: 
            case 0x15: 
            case 0x16: 
            case 0x17: 
            case 0x18: 
            case 0x19: 
            case 0x1A: 
            case 0x1B: 
            case 0x1C: 
            case 0x1D: 
            case 0x1E: 
            case 0x1F: 
            case 0x20: 
            case 0x21: 
            case 0x22: 
            case 0x23: 
            case 0x24: 
            case 0x25: 
            case 0x26: 
            case 0x27: 
            case 0x28: 
            case 0x29: goto _459;

            case 0x2A: goto _460;

        }
    } else {

        if( input < 0x2F ) {
            goto _459;

        } else if( input == 0x2F ) {

        } else if( input < 0x110000 ) {
            goto _459;

        } else {

}    }_500:
    __quex_debug_drop_out(460);
    me->buffer._input_p = position[0];
    goto TERMINAL_93;


    __quex_assert_no_passage();
_438: /* (438 from 438) (438 from 437) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(438);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(438, 501);

        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _438;

    }
_501:
    __quex_debug_drop_out(438);
    goto TERMINAL_27;


    __quex_assert_no_passage();
_453: /* (453 from 451) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(453);
    if( input < 0xA ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD_FORWARD(453, 502);

            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: goto _451;

        }
    } else {

        if( input == 0xA ) {

        } else if( input < 0x100 ) {
            goto _451;

        } else {

}    }_502:
    __quex_debug_drop_out(453);
    
    goto _490; /* TERMINAL_FAILURE */


    __quex_assert_no_passage();
_454: /* (454 from 451) */

    ++(me->buffer._input_p);
    __quex_debug_state(454);
    __quex_debug_drop_out(454);
    goto TERMINAL_117;


    __quex_assert_no_passage();
_455: /* (455 from 448) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(455);
    if( input < 0x2A ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD_FORWARD(455, 504);

            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: 
            case 0xA: 
            case 0xB: 
            case 0xC: 
            case 0xD: 
            case 0xE: 
            case 0xF: 
            case 0x10: 
            case 0x11: 
            case 0x12: 
            case 0x13: 
            case 0x14: 
            case 0x15: 
            case 0x16: 
            case 0x17: 
            case 0x18: 
            case 0x19: 
            case 0x1A: 
            case 0x1B: 
            case 0x1C: 
            case 0x1D: 
            case 0x1E: 
            case 0x1F: 
            case 0x20: 
            case 0x21: 
            case 0x22: 
            case 0x23: 
            case 0x24: 
            case 0x25: 
            case 0x26: 
            case 0x27: 
            case 0x28: 
            case 0x29: goto _492;

        }
    } else {

        if( input == 0x2A ) {
            goto _498;

        } else if( input < 0x110000 ) {
            goto _492;

        } else {

}    }_504:
    __quex_debug_drop_out(455);
    goto TERMINAL_93;


    __quex_assert_no_passage();
_457: /* (457 from 456) */

    ++(me->buffer._input_p);
    __quex_debug_state(457);
    __quex_debug_drop_out(457);
    goto TERMINAL_55;


    __quex_assert_no_passage();
_461: /* (461 from 458) */

    ++(me->buffer._input_p);
    __quex_debug_state(461);
    __quex_debug_drop_out(461);
    goto TERMINAL_91;


    __quex_assert_no_passage();
_462: /* (462 from 447) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(462);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(462, 507);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: goto _449;

        case 0x6E: goto _468;

        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_507:
    __quex_debug_drop_out(462);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_463: /* (463 from 447) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(463);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(463, 508);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: goto _449;

        case 0x72: goto _464;

        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_508:
    __quex_debug_drop_out(463);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_464: /* (464 from 463) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(464);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(464, 509);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: goto _449;

        case 0x75: goto _465;

        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_509:
    __quex_debug_drop_out(464);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_465: /* (465 from 464) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(465);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(465, 510);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: goto _449;

        case 0x63: goto _466;

        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_510:
    __quex_debug_drop_out(465);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_466: /* (466 from 465) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(466);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(466, 511);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: goto _449;

        case 0x74: goto _467;

        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_511:
    __quex_debug_drop_out(466);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_467: /* (467 from 466) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(467);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(467, 512);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_512:
    __quex_debug_drop_out(467);
    goto TERMINAL_6;


    __quex_assert_no_passage();
_468: /* (468 from 462) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(468);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(468, 513);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: goto _449;

        case 0x64: goto _469;

        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_513:
    __quex_debug_drop_out(468);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_469: /* (469 from 468) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(469);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(469, 514);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_514:
    __quex_debug_drop_out(469);
    goto TERMINAL_14;


    __quex_assert_no_passage();
_470: /* (470 from 446) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(470);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(470, 515);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: goto _449;

        case 0x75: goto _471;

        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_515:
    __quex_debug_drop_out(470);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_471: /* (471 from 470) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(471);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(471, 516);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: goto _449;

        case 0x62: goto _472;

        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_516:
    __quex_debug_drop_out(471);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_472: /* (472 from 471) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(472);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(472, 517);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: goto _449;

        case 0x6C: goto _473;

        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_517:
    __quex_debug_drop_out(472);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_473: /* (473 from 472) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(473);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(473, 518);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: goto _449;

        case 0x65: goto _474;

        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_518:
    __quex_debug_drop_out(473);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_474: /* (474 from 473) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(474);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(474, 519);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_519:
    __quex_debug_drop_out(474);
    goto TERMINAL_12;


    __quex_assert_no_passage();
_476: /* (476 from 475) */

    ++(me->buffer._input_p);
    __quex_debug_state(476);
    __quex_debug_drop_out(476);
    goto TERMINAL_45;


    __quex_assert_no_passage();
_477: /* (477 from 443) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(477);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(477, 521);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: goto _449;

        case 0x70: goto _478;

        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_521:
    __quex_debug_drop_out(477);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_478: /* (478 from 477) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(478);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(478, 522);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: goto _449;

        case 0x65: goto _479;

        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_522:
    __quex_debug_drop_out(478);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_479: /* (479 from 478) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(479);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(479, 523);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: goto _449;

        case 0x63: goto _480;

        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_523:
    __quex_debug_drop_out(479);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_480: /* (480 from 479) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(480);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(480, 524);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: goto _449;

        case 0x74: goto _481;

        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_524:
    __quex_debug_drop_out(480);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_481: /* (481 from 480) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(481);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(481, 525);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_525:
    __quex_debug_drop_out(481);
    goto TERMINAL_16;


    __quex_assert_no_passage();
_482: /* (482 from 442) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(482);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(482, 526);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: goto _449;

        case 0x6D: goto _483;

        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_526:
    __quex_debug_drop_out(482);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_483: /* (483 from 482) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(483);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(483, 527);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: goto _449;

        case 0x70: goto _484;

        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_527:
    __quex_debug_drop_out(483);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_484: /* (484 from 483) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(484);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(484, 528);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_528:
    __quex_debug_drop_out(484);
    goto TERMINAL_8;


    __quex_assert_no_passage();
_485: /* (485 from 441) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(485);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(485, 529);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: goto _449;

        case 0x74: goto _486;

        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_529:
    __quex_debug_drop_out(485);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_486: /* (486 from 485) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(486);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(486, 530);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_530:
    __quex_debug_drop_out(486);
    goto TERMINAL_10;


    __quex_assert_no_passage();
_487: /* (487 from 439) */

    ++(me->buffer._input_p);
    __quex_debug_state(487);
    __quex_debug_drop_out(487);
    goto TERMINAL_95;


    __quex_assert_no_passage();
_439: /* (439 from 437) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(439);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(439, 532);

        case 0x2F: goto _487;

    }
_532:
    __quex_debug_drop_out(439);
    
    goto _490; /* TERMINAL_FAILURE */


    __quex_assert_no_passage();
_441: /* (441 from 437) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(441);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(441, 533);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: goto _449;

        case 0x6E: goto _485;

        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_533:
    __quex_debug_drop_out(441);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_442: /* (442 from 437) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(442);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(442, 534);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: goto _449;

        case 0x75: goto _482;

        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_534:
    __quex_debug_drop_out(442);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_443: /* (443 from 437) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(443);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(443, 535);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: goto _449;

        case 0x78: goto _477;

        case 0x79: 
        case 0x7A: goto _449;

    }
_535:
    __quex_debug_drop_out(443);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_444: /* (444 from 437) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(444);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(444, 536);

        case 0x2D: goto _475;

    }
_536:
    __quex_debug_drop_out(444);
    
    goto _490; /* TERMINAL_FAILURE */


    __quex_assert_no_passage();
_445: /* (445 from 437) */

    ++(me->buffer._input_p);
    __quex_debug_state(445);
    __quex_debug_drop_out(445);
    goto TERMINAL_18;


    __quex_assert_no_passage();
_446: /* (446 from 437) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(446);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(446, 538);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: goto _449;

        case 0x6F: goto _470;

        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_538:
    __quex_debug_drop_out(446);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_447: /* (447 from 437) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(447);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(447, 539);

        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: goto _449;

        case 0x65: goto _462;

        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: goto _449;

        case 0x74: goto _463;

        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _449;

    }
_539:
    __quex_debug_drop_out(447);
    goto TERMINAL_32;


    __quex_assert_no_passage();
_448: /* (448 from 437) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(448);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD_FORWARD(448, 540);

        case 0x2A: goto _455;

        case 0x2F: goto _456;

    }
_540:
    __quex_debug_drop_out(448);
    
    goto _490; /* TERMINAL_FAILURE */


    __quex_assert_no_passage();
_450: /* (450 from 437) */

    ++(me->buffer._input_p);
    __quex_debug_state(450);
    __quex_debug_drop_out(450);
    goto TERMINAL_20;


    __quex_assert_no_passage();
_452: /* (452 from 437) */

    ++(me->buffer._input_p);
    __quex_debug_state(452);
    __quex_debug_drop_out(452);
    goto TERMINAL_22;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */

    /* Lexeme setup: 
     *
     * There is a temporary zero stored at the end of each lexeme, if the action 
     * references to the 'Lexeme'. 'LexemeNull' provides a reference to an empty
     * zero terminated string.                                                    */
#if defined(QUEX_OPTION_ASSERTS)
#   define Lexeme       QUEX_NAME(access_Lexeme)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeBegin  QUEX_NAME(access_LexemeBegin)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeL      QUEX_NAME(access_LexemeL)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeEnd    QUEX_NAME(access_LexemeEnd)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#else
#   define Lexeme       (me->buffer._lexeme_start_p)
#   define LexemeBegin  Lexeme
#   define LexemeL      ((size_t)(me->buffer._input_p - me->buffer._lexeme_start_p))
#   define LexemeEnd    me->buffer._input_p
#endif

#define LexemeNull      (&QUEX_LEXEME_NULL)

TERMINAL_32:
    __quex_debug("* terminal 32:   [:alpha:]+\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, LexemeL);
    {
#   line 25 "sql.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_IDENTIFIER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2927 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_91:
    __quex_debug("* terminal 91:   \"/*\"([^*]|[\\r\\n]|(\\*+([^*/]|[\\r\\n])))*\"*/\"\n");
    __QUEX_COUNT_VOID(self.counter);
    {
#   line 30 "sql.qx"
    self_send(QUEX_TKN_COMMENT);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2940 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_4:
    __quex_debug("* terminal 4:   [ \\t\\r\\n]+\n");
    __QUEX_COUNT_VOID(self.counter);
    {

    }
    goto __REENTRY_PREPARATION;

TERMINAL_6:
    __quex_debug("* terminal 6:   \"struct\"\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, 6);
    {
#   line 15 "sql.qx"
    self_send(QUEX_TKN_STRUCT);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2961 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_8:
    __quex_debug("* terminal 8:   \"jump\"\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, 4);
    {
#   line 16 "sql.qx"
    self_send(QUEX_TKN_JUMP);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2974 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_10:
    __quex_debug("* terminal 10:   \"int\"\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, 3);
    {
#   line 17 "sql.qx"
    self_send(QUEX_TKN_TYPE_INT);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2987 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_12:
    __quex_debug("* terminal 12:   \"double\"\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, 6);
    {
#   line 18 "sql.qx"
    self_send(QUEX_TKN_TYPE_DOUBLE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3000 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_45:
    __quex_debug("* terminal 45:   --(.)*\\n\n");
    __QUEX_COUNT_VOID(self.counter);
    {
#   line 28 "sql.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_GREEDYCOMMENT);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3014 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_14:
    __quex_debug("* terminal 14:   \"send\"\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, 4);
    {
#   line 19 "sql.qx"
    self_send(QUEX_TKN_SEND);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3027 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_16:
    __quex_debug("* terminal 16:   \"expect\"\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, 6);
    {
#   line 20 "sql.qx"
    self_send(QUEX_TKN_EXPECT);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3040 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_18:
    __quex_debug("* terminal 18:   \";\"\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, 1);
    {
#   line 21 "sql.qx"
    self_send(QUEX_TKN_SEMICOLON);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3053 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_20:
    __quex_debug("* terminal 20:   \"{\"\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, 1);
    {
#   line 22 "sql.qx"
    self_send(QUEX_TKN_BRACKET_OPEN);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3066 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_117:
    __quex_debug("* terminal 117:   \\\"([^\"\\\\]*(\\\\.[^\"\\\\]*)*)\\\"\n");
    __QUEX_COUNT_VOID(self.counter);
    {
#   line 34 "sql.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_STRING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3080 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_22:
    __quex_debug("* terminal 22:   \"}\"\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, 1);
    {
#   line 23 "sql.qx"
    self_send(QUEX_TKN_BRACKET_CLOSE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3093 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_55:
    __quex_debug("* terminal 55:   \"//\"(.)*\\n\n");
    __QUEX_COUNT_VOID(self.counter);
    {
#   line 29 "sql.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_GREEDYCOMMENT);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3107 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_27:
    __quex_debug("* terminal 27:   [0-9]+\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, LexemeL);
    QUEX_LEXEME_TERMINATING_ZERO_SET(&me->buffer);
    {
#   line 24 "sql.qx"
    self_write_token_p()->number = atoi((char*)(Lexeme));
    self_send(QUEX_TKN_NUMBER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3122 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_93:
    __quex_debug("* terminal 93:   \"/*\"\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, 2);
    {
#   line 31 "sql.qx"
    self_send(QUEX_TKN_COMMENTSTART);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3135 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_95:
    __quex_debug("* terminal 95:   \"*/\"\n");
    __QUEX_COUNT_NEWLINE_N_ZERO_COLUMN_N_FIXED(self.counter, 2);
    {
#   line 32 "sql.qx"
    self_send(QUEX_TKN_COMMENTEND);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3148 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

_488: /* TERMINAL: END_OF_STREAM */
    __QUEX_COUNT_END_OF_STREAM_EVENT(self.counter);
    {
#   line 10 "sql.qx"
    self_send(QUEX_TKN_TERMINATION);
    
#   line 3159 "sqllexer.cpp"

    }
    /* End of Stream causes a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.                    */
    RETURN;          

_490: /* TERMINAL: FAILURE */
    if(QUEX_NAME(Buffer_is_end_of_file)(&me->buffer)) {
        /* Init state is going to detect 'input == buffer limit code', and
         * enter the reload procedure, which will decide about 'end of stream'. */
    } else {
        /* In init state 'input = *input_p' and we need to increment
         * in order to avoid getting stalled. Else, input = *(input_p - 1),
         * so 'input_p' points already to the next character.              */
        if( me->buffer._input_p == me->buffer._lexeme_start_p ) {
            /* Step over non-matching character */
            ++(me->buffer._input_p);
        }
    }
    __QUEX_COUNT_VOID(self.counter);
    {
#   line 12 "sql.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_FAILURE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3186 "sqllexer.cpp"

    }
    goto __REENTRY_PREPARATION;

__REENTRY_PREPARATION:
    /* (*) Common point for **restarting** lexical analysis.
     *     at each time when CONTINUE is called at the end of a pattern. */
 

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL

#   ifndef __QUEX_OPTION_PLAIN_ANALYZER_OBJECT
#   ifdef  QUEX_OPTION_TOKEN_POLICY_QUEUE
    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) RETURN;
#   else
    if( self_token_get_id() != __QUEX_SETTING_TOKEN_ID_UNINITIALIZED) RETURN;
#   endif
#   endif
    


    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */

    /*  If a mode change happened, then the function must first return and
     *  indicate that another mode function is to be called. At this point, 
     *  we to force a 'return' on a mode change. 
     *
     *  Pseudo Code: if( previous_mode != current_mode ) {
     *                   return 0;
     *               }
     *
     *  When the analyzer returns, the caller function has to watch if a mode change
     *  occurred. If not it can call this function again.                               */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)        || defined(QUEX_OPTION_ASSERTS)
    if( me->DEBUG_analyzer_function_at_entry != me->current_analyzer_function ) 
#   endif
    { 
#       if defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)
        self_token_set_id(__QUEX_SETTING_TOKEN_ID_UNINITIALIZED);
        RETURN;
#       elif defined(QUEX_OPTION_ASSERTS)
        QUEX_ERROR_EXIT("Mode change without immediate return from the lexical analyzer.");
#       endif
    }

    goto __REENTRY;

    __quex_assert_no_passage();
__RELOAD_FORWARD:
    __quex_debug1("__RELOAD_FORWARD");

    __quex_assert(input == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {
        __quex_debug_reload_before();
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);
        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
__STATE_ROUTER:
    switch( target_state_index ) {
        case 437: { goto _437; }
        case 438: { goto _438; }
        case 439: { goto _439; }
        case 440: { goto _440; }
        case 441: { goto _441; }
        case 442: { goto _442; }
        case 443: { goto _443; }
        case 444: { goto _444; }
        case 445: { goto _445; }
        case 446: { goto _446; }
        case 447: { goto _447; }
        case 448: { goto _448; }
        case 449: { goto _449; }
        case 450: { goto _450; }
        case 451: { goto _451; }
        case 452: { goto _452; }
        case 453: { goto _453; }
        case 454: { goto _454; }
        case 455: { goto _455; }
        case 456: { goto _456; }
        case 457: { goto _457; }
        case 458: { goto _458; }
        case 459: { goto _459; }
        case 460: { goto _460; }
        case 461: { goto _461; }
        case 462: { goto _462; }
        case 463: { goto _463; }
        case 464: { goto _464; }
        case 465: { goto _465; }
        case 466: { goto _466; }
        case 467: { goto _467; }
        case 468: { goto _468; }
        case 469: { goto _469; }
        case 470: { goto _470; }
        case 471: { goto _471; }
        case 472: { goto _472; }
        case 473: { goto _473; }
        case 474: { goto _474; }
        case 475: { goto _475; }
        case 476: { goto _476; }
        case 477: { goto _477; }
        case 478: { goto _478; }
        case 479: { goto _479; }
        case 480: { goto _480; }
        case 481: { goto _481; }
        case 482: { goto _482; }
        case 483: { goto _483; }
        case 484: { goto _484; }
        case 485: { goto _485; }
        case 486: { goto _486; }
        case 487: { goto _487; }
        case 488: { goto _488; }
        case 491: { goto _491; }
        case 492: { goto _492; }
        case 493: { goto _493; }
        case 494: { goto _494; }
        case 495: { goto _495; }
        case 496: { goto _496; }
        case 497: { goto _497; }
        case 498: { goto _498; }
        case 499: { goto _499; }
        case 500: { goto _500; }
        case 501: { goto _501; }
        case 502: { goto _502; }
        case 504: { goto _504; }
        case 507: { goto _507; }
        case 508: { goto _508; }
        case 509: { goto _509; }
        case 510: { goto _510; }
        case 511: { goto _511; }
        case 512: { goto _512; }
        case 513: { goto _513; }
        case 514: { goto _514; }
        case 515: { goto _515; }
        case 516: { goto _516; }
        case 517: { goto _517; }
        case 518: { goto _518; }
        case 519: { goto _519; }
        case 521: { goto _521; }
        case 522: { goto _522; }
        case 523: { goto _523; }
        case 524: { goto _524; }
        case 525: { goto _525; }
        case 526: { goto _526; }
        case 527: { goto _527; }
        case 528: { goto _528; }
        case 529: { goto _529; }
        case 530: { goto _530; }
        case 532: { goto _532; }
        case 533: { goto _533; }
        case 534: { goto _534; }
        case 535: { goto _535; }
        case 536: { goto _536; }
        case 538: { goto _538; }
        case 539: { goto _539; }
        case 540: { goto _540; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */

    /* Prevent compiler warning 'unused variable': use variables once in a part of the code*/
    /* that is never reached (and deleted by the compiler anyway).*/
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    QUEX_ERROR_EXIT("Unreachable code has been reached.\n");
#   undef ONE_AND_ONLY
#   undef self
}
#include <quex/code_base/temporary_macros_off>
QUEX_NAMESPACE_MAIN_CLOSE


QUEX_NAMESPACE_TOKEN_OPEN

const char*
QUEX_NAME_TOKEN(map_id_to_name)(const QUEX_TYPE_TOKEN_ID TokenID)
{
   static char  error_string[64];
   static const char  uninitialized_string[] = "<UNINITIALIZED>";
   static const char  termination_string[]   = "<TERMINATION>";
#  if defined(QUEX_OPTION_INDENTATION_TRIGGER)
   static const char  indent_string[]        = "<INDENT>";
   static const char  dedent_string[]        = "<DEDENT>";
   static const char  nodent_string[]        = "<NODENT>";
#  endif
   static const char  token_id_str_BRACKET_CLOSE[] = "BRACKET_CLOSE";
   static const char  token_id_str_BRACKET_OPEN[]  = "BRACKET_OPEN";
   static const char  token_id_str_COMMENT[]       = "COMMENT";
   static const char  token_id_str_COMMENTEND[]    = "COMMENTEND";
   static const char  token_id_str_COMMENTSTART[]  = "COMMENTSTART";
   static const char  token_id_str_EXPECT[]        = "EXPECT";
   static const char  token_id_str_FAILURE[]       = "FAILURE";
   static const char  token_id_str_GREEDYCOMMENT[] = "GREEDYCOMMENT";
   static const char  token_id_str_IDENTIFIER[]    = "IDENTIFIER";
   static const char  token_id_str_JUMP[]          = "JUMP";
   static const char  token_id_str_NUMBER[]        = "NUMBER";
   static const char  token_id_str_SEMICOLON[]     = "SEMICOLON";
   static const char  token_id_str_SEND[]          = "SEND";
   static const char  token_id_str_STRING[]        = "STRING";
   static const char  token_id_str_STRUCT[]        = "STRUCT";
   static const char  token_id_str_TYPE_DOUBLE[]   = "TYPE_DOUBLE";
   static const char  token_id_str_TYPE_INT[]      = "TYPE_INT";
       

   /* NOTE: This implementation works only for token id types that are 
    *       some type of integer or enum. In case an alien type is to
    *       used, this function needs to be redefined.                  */
   switch( TokenID ) {
   default: {
       __QUEX_STD_sprintf(error_string, "<UNKNOWN TOKEN-ID: %i>", (int)TokenID);
       return error_string;
   }
   case QUEX_TKN_TERMINATION:    return termination_string;
   case QUEX_TKN_UNINITIALIZED:  return uninitialized_string;
#  if defined(QUEX_OPTION_INDENTATION_TRIGGER)
   case QUEX_TKN_INDENT:         return indent_string;
   case QUEX_TKN_DEDENT:         return dedent_string;
   case QUEX_TKN_NODENT:         return nodent_string;
#  endif
   case QUEX_TKN_BRACKET_CLOSE: return token_id_str_BRACKET_CLOSE;
   case QUEX_TKN_BRACKET_OPEN:  return token_id_str_BRACKET_OPEN;
   case QUEX_TKN_COMMENT:       return token_id_str_COMMENT;
   case QUEX_TKN_COMMENTEND:    return token_id_str_COMMENTEND;
   case QUEX_TKN_COMMENTSTART:  return token_id_str_COMMENTSTART;
   case QUEX_TKN_EXPECT:        return token_id_str_EXPECT;
   case QUEX_TKN_FAILURE:       return token_id_str_FAILURE;
   case QUEX_TKN_GREEDYCOMMENT: return token_id_str_GREEDYCOMMENT;
   case QUEX_TKN_IDENTIFIER:    return token_id_str_IDENTIFIER;
   case QUEX_TKN_JUMP:          return token_id_str_JUMP;
   case QUEX_TKN_NUMBER:        return token_id_str_NUMBER;
   case QUEX_TKN_SEMICOLON:     return token_id_str_SEMICOLON;
   case QUEX_TKN_SEND:          return token_id_str_SEND;
   case QUEX_TKN_STRING:        return token_id_str_STRING;
   case QUEX_TKN_STRUCT:        return token_id_str_STRUCT;
   case QUEX_TKN_TYPE_DOUBLE:   return token_id_str_TYPE_DOUBLE;
   case QUEX_TKN_TYPE_INT:      return token_id_str_TYPE_INT;

   }
}

QUEX_NAMESPACE_TOKEN_CLOSE

