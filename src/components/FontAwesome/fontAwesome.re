external myFontAwesome : ReasonReact.reactClass = "./../../../node_modules/react-fontawesome" [@@bs.module];

let component = ReasonReact.statelessComponent "FontAwesome";

let make ::name children =>
  ReasonReact.wrapJsForReason
    reactClass::myFontAwesome
    props::{
      "name": name
    }
    children;