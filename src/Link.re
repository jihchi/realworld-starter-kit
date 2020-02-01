type location';

external make: string => location' = "%identity";
external toString: location' => string = "%identity";

let home = make("/");
let settings = make("/#/settings");
let register = make("/#/register");
let login = make("/#/login");
let createArticle = make("/#/editor");
let editArticle = (~slug) => make(Printf.sprintf("/#/editor/%s", slug));
let article = (~slug) => make(Printf.sprintf("/#/article/%s", slug));
let viewProfile = (~username) =>
  make(Printf.sprintf("/#/profile/%s", username));
let viewFavorites = (~username) =>
  make(Printf.sprintf("/#/profile/%s/favorites", username));

[@react.component]
let make = (~className="", ~location, ~children) => {
  let href = location->toString;

  <a
    className
    href
    onClick={event =>
      if (!event->ReactEvent.Mouse.defaultPrevented
          && event->ReactEvent.Mouse.button == 0
          && !event->ReactEvent.Mouse.altKey
          && !event->ReactEvent.Mouse.ctrlKey
          && !event->ReactEvent.Mouse.metaKey
          && !event->ReactEvent.Mouse.shiftKey) {
        event->ReactEvent.Mouse.preventDefault;
        href->ReasonReactRouter.push;
      }
    }>
    children
  </a>;
};