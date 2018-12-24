#include <stdio.h>

/**
 *  Q & A Flow:
 *
 *                  +----------------------------+
 *                  V                            |
 *  Start -> Ask Question & Accept Answer -> Provide Response -> End
 *
 * I'm worried the behavior will be too simple... like really just a CLI runner...
 * Is there a more interesting application?
 * Also it needs to drive the state of the behavior through its functions.
 * And consume the responses, whatever they may be from the behavior.
 * Well, another KIND of UI could be written to support the behaviors.
 *  - Dating App -
 *  - Dinner party game -
 *      Another idea: It could support switching which conversation you're having: multiple conversations at once
 *      How sophisiticated would this logic have to be?
 * Each conversation is an isolated session - managing multiple behaviors
 *  Behaviors could also represent interactions with objects * <-- these all seem wacky
 * That is, the pattern supports swapping out consumers as well, (if the behaviors are decoupled).
 * Is it true that all designs go "both ways" if things are decoupled?
 *
 */


class BehaviorRequest;
class BehaviorResponse;

class AbstractBehavior {
public:
  bool isReady() = 0; // or isDone?
  BehaviorRequest* getNextRequest() = 0; // moves the question state forward
  BehaviorRequest* getCurRequest() = 0;
  bool respondToRequest(BehaviorResposne* response) = 0;
};

int main()
{
  printf("Hello, World!\n");
  return 0;
}
