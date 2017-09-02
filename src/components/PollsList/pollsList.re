type poll = {
  username: string,
  character: string,
  payment: bool
};

let vDOM = Helpers.vDOM;

let component = ReasonReact.statelessComponent "PollsList";

let make ::items _children => {  
  {
    ...component,
    render: fun self => {
      let pollItems = items |> List.map(fun item => <li>(vDOM item.username) (vDOM " - ") (vDOM item.character) </li>);
      <ul >
      (ReasonReact.arrayToElement (Array.of_list pollItems))
      </ul>
    }
  }
};