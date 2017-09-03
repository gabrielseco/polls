external myFontAwesome : ReasonReact.reactClass = "./../../../node_modules/react-fontawesome" [@@bs.module];

let component = ReasonReact.statelessComponent "FontAwesome";

let make ::name ::className=?  children =>
  ReasonReact.wrapJsForReason
    reactClass::myFontAwesome
    props::{
      "name": name,
      "className": className
    }
    children;